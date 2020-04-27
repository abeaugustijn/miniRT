/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal_triangle.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 21:39:49 by abe           #+#   #+#                  */
/*   Updated: 2020/03/09 13:07:45 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Gets the normal vector of a triangle. If the normal stored in the triangle
**	is not normalized, we assume that it was not generated yet and generate
**	it again.
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f} normal
*/

t_vec3f	normal_triangle(t_rayres rayres, t_ray ray, t_info *info)
{
	t_vec3f	res;
	t_vec3f	ca;
	t_vec3f cb;

	(void)info;
	ca = vec_from_to(rayres.obj->points[2], rayres.obj->points[0]);
	cb = vec_from_to(rayres.obj->points[2], rayres.obj->points[1]);
	res = vec_crossp(ca, cb);
	return (fix_normal(ray.direction, vec_normalize(res)));
}
