/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:01 by abe               #+#    #+#             */
/*   Updated: 2020/03/07 16:46:08 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <math.h>

/*
**	Calculate whether a given ray intersects with a triangle.
**
**	@param {t_object *} tr (triangle)
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {double}
*/

double	intersect_triangle(t_object *tr, t_ray ray, t_info *info)
{
	double		t;
	t_object	pl;

	ft_bzero(&pl, sizeof(t_object));
	pl.type = PL;
	pl.location = tr->points[0];
	pl.orientation = normal(rayres_new(tr, vec_new(0, 0, 0)), info);
	fix_normal(ray.direction, &pl.orientation);
	if (float_compare(vec_dotp(pl.orientation, ray.direction), 0))
		return (INFINITY);
	t = intersect(&pl, ray, info);
	return (triangle_inside(tr, pl.orientation, ray_point(ray, t))
			? t : INFINITY);
}
