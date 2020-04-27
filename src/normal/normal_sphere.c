/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal_sphere.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 21:39:49 by abe           #+#   #+#                  */
/*   Updated: 2020/03/10 14:14:32 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Gets the normal vector of a sphere, on a certain point where the ray hit
**	the sphere.
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f} normal
*/

t_vec3f	normal_sphere(t_rayres rayres, t_ray ray, t_info *info)
{
	(void)info;
	(void)ray;
	return (fix_normal(ray.direction,
				vec_from_to(rayres.obj->location, rayres.p)));
}
