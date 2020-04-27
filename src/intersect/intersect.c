/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:57:06 by abe           #+#   #+#                  */
/*   Updated: 2020/03/10 14:32:18 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include <minirt.h>

/*
**	Determines whether a ray intersects with a given object.
**
**	@param {t_object *} obj
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {double} - the distance from the ray to the given object
*/

double	intersect(t_object *obj, t_ray ray, t_vec3f *normal, t_info *info)
{
	return (g_intersectjump[obj->type](obj, ray, normal, info));
}
