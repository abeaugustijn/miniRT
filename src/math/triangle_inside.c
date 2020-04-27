/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_inside.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 12:12:43 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 13:50:12 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Checks whether a given point falls inside of a triangle.
**
**	@param {t_object *} tr
**	@param {t_vec3f} tr_normal
**	@param {t_vec3f} p
**
**	@return {bool} - true if the point falls inside the triangle
*/

bool	triangle_inside(t_object *tr, t_vec3f tr_normal, t_vec3f p)
{
	t_vec3f	edges[3];
	t_vec3f	directions[3];
	t_vec3f	normal_inverse;

	edges[0] = vec_sub(tr->points[1], tr->points[0]);
	edges[1] = vec_sub(tr->points[2], tr->points[1]);
	edges[2] = vec_sub(tr->points[0], tr->points[2]);
	directions[0] = vec_sub(p, tr->points[0]);
	directions[1] = vec_sub(p, tr->points[1]);
	directions[2] = vec_sub(p, tr->points[2]);
	normal_inverse = vec_multiply(tr_normal, -1);
	return ((vec_dotp(tr_normal, vec_crossp(edges[0], directions[0])) >= 0 &&
			vec_dotp(tr_normal, vec_crossp(edges[1], directions[1])) >= 0 &&
			vec_dotp(tr_normal, vec_crossp(edges[2], directions[2])) >= 0) ||
		(vec_dotp(normal_inverse, vec_crossp(edges[0], directions[0])) > 0 &&
		vec_dotp(normal_inverse, vec_crossp(edges[1], directions[1])) > 0 &&
		vec_dotp(normal_inverse, vec_crossp(edges[2], directions[2])) > 0));
}
