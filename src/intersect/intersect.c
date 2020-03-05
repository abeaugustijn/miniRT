/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:57:06 by abe               #+#    #+#             */
/*   Updated: 2020/03/05 18:55:17 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include <miniRT.h>

/*
**	Determines whether a ray intersects with a given object.
**
**	@param {t_object *} obj
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {double} - the distance from the ray to the given object
*/

double	intersect(t_object *obj, t_ray ray, t_info *info)
{
	return (g_intersectjump[obj->type](obj, ray, info));
}
