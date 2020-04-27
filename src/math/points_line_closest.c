/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   points_line_closest.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 11:23:31 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/07 09:46:10 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>
#include <libft.h>

/*
**	Get the determinant of a matrix.
**
**	@param {t_vec3f[3]} mat
**
**	@return {double}
*/

static double	determinant(t_vec3f mat[3])
{
	return (mat[0].x * (mat[1].y * mat[2].z - mat[2].y * mat[1].z)
		- mat[0].y * (mat[1].x * mat[2].z - mat[1].z * mat[2].x)
		+ mat[0].z * (mat[1].x * mat[2].y - mat[1].y * mat[2].x));
}

/*
**	Set the three matrices according to Cramer's rule.
**
**	@param {t_vec3f[3][3]} mats
**	@param {t_vec3f[3]} to_solve
**	@param {t_vec3f} totals
*/

static void		set_mats(t_vec3f mats[3][3], t_vec3f to_solve[3],
		t_vec3f totals)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (j == i)
				mats[i][j] = totals;
			else
				mats[i][j] = to_solve[j];
			j++;
		}
		i++;
	}
}

/*
**	Solves a system of three linear equations and returns the result in the form
**	of a vector.
**	Following https://www.geeksforgeeks.org/system-linear-equations-three-\
**		variables-using-cramers-rule/
**
**	@param {t_vec4f *} to_solve - an array of three vectors representing the
**		equations.
**
**	@return {t_vec3f}
*/

static t_vec3f	points_line_closest_solve(t_vec3f to_solve[3], t_vec3f totals)
{
	double	determinants[4];
	t_vec3f	mats[3][3];
	size_t	i;

	set_mats(mats, to_solve, totals);
	determinants[0] = determinant(to_solve);
	i = 0;
	while (i < 3)
	{
		determinants[i + 1] = determinant(mats[i]);
		i++;
	}
	if (determinants[0])
		return (vec_new(determinants[1] / determinants[0],
					determinants[2] / determinants[0],
					determinants[3] / determinants[0]));
	else
		return (vec_new(0, 0, 0));
}

/*
**	Find the points on two lines which are closest to each other. The result
**	will be stored in the 'results' array with the first element being the point
**	on line_a and the second element the point on line_b.
**
**	@param {t_line} line_a
**	@param {t_line} line_b
**	@param {double []} results - should have space for two elements
*/

void			points_line_closest(t_line line_a, t_line line_b,
		double results[])
{
	t_vec3f	to_solve[3];
	t_vec3f	origin_from_to;
	t_vec3f	solve_res;
	t_vec3f	c_dir;

	origin_from_to = vec_sub(line_b.origin, line_a.origin);
	c_dir = vec_normalize(vec_crossp(line_b.direction, line_a.direction));
	to_solve[0] = line_a.direction;
	to_solve[1] = vec_multiply(line_b.direction, -1);
	to_solve[2] = c_dir;
	solve_res = points_line_closest_solve(to_solve, origin_from_to);
	ft_memcpy(results, &solve_res, sizeof(double) * 2);
}
