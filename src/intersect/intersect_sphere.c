/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_sphere.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:49:01 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 12:29:49 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>
#include <libft.h>

static void		swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
**	Calculate whether a given ray intersects with a sphere.
**
**	@param {t_object *} sp (sphere)
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {double}
*/

double			intersect_sphere(t_object *sp, t_ray ray, t_vec3f *normal,
		t_info *info)
{
	t_vec3f	orig_to_sp;
	double	tca;
	double	thc;
	double	d2;
	double	t[2];

	(void)normal;
	(void)info;
	orig_to_sp = vec_sub(sp->location, ray.origin);
	tca = vec_dotp(orig_to_sp, ray.direction);
	d2 = vec_dotp(orig_to_sp, orig_to_sp) - pow(tca, 2);
	if (d2 > sp->size / 2)
		return (INFINITY);
	thc = sqrt(sp->size / 2 - d2);
	t[0] = tca - thc;
	t[1] = tca + thc;
	if (t[0] > t[1])
		swap(&t[0], &t[1]);
	if (t[0] < 0)
	{
		t[0] = t[1];
		if (t[0] < 0)
			return (INFINITY);
	}
	return (t[0]);
}
