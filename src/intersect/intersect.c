/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:57:06 by abe               #+#    #+#             */
/*   Updated: 2020/02/11 15:51:22 by aaugusti         ###   ########.fr       */
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
**	@return {bool} - true if intersect
*/

bool	intersect(t_object *obj, t_ray ray, t_info *info)
{
	return (g_intersectjump[obj->type](obj, ray, info));
}
