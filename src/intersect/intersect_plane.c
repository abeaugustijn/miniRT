/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_plane.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:53:42 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 12:29:33 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

/*
**	Calculate whether a given ray intersects with a plane.
**
**	@param {t_object *} pl (plane)
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {double}
*/

double	intersect_plane(t_object *pl, t_ray ray, t_vec3f *normal, t_info *info)
{
	double	t;

	(void)normal;
	(void)info;
	t = vec_dotp(vec_sub(pl->location, ray.origin), pl->dir_vecs.forward) /
		vec_dotp(ray.direction, pl->dir_vecs.forward);
	if (t < 0 ||
			float_compare(vec_dotp(ray.direction, pl->dir_vecs.forward), 0))
		return (INFINITY);
	return (t);
}
