/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:53:42 by abe               #+#    #+#             */
/*   Updated: 2020/03/09 12:06:31 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
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

double	intersect_plane(t_object *pl, t_ray ray, t_info *info)
{
	double	t;

	(void)info;
	t = vec_dotp(vec_sub(pl->location, ray.origin), pl->orientation) /
		vec_dotp(ray.direction, pl->orientation);
	if (t < 0 || float_compare(vec_dotp(ray.direction, pl->orientation), 0))
		return (INFINITY);
	return (t);
}
