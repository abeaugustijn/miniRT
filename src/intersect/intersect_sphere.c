/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:01 by abe               #+#    #+#             */
/*   Updated: 2020/03/07 15:32:50 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	Calculate whether a given ray intersects with a sphere.
**
**	@param {t_object *} sp (sphere)
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {double}
*/

double	intersect_sphere(t_object *sp, t_ray ray, t_info *info)
{
	double	t;
	double	x;
	double	y;
	t_vec3f	p;

	(void)info;
	t = vec_dotp(vec_sub(sp->location, ray.origin), ray.direction);
	if (t < 0)
		return (INFINITY);
	p = vec_add(ray.origin, vec_multiply(ray.direction, t));
	y = vec_len(vec_sub(sp->location, p));
	if (y > sp->size / 2)
		return (INFINITY);
	x = sqrt(pow(sp->size / 2, 2) - pow(y, 2));
	return (fabs(t - x));
}
