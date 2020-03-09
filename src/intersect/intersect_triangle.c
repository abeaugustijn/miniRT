/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:01 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/09 13:06:40 by aaugusti         ###   ########.fr       */
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
	t_vec3f		norm;

	norm = normal(rayres_new(tr, vec_new(0, 0, 0)), ray, info);
	t = intersect(&(t_object){
			.type = PL,
			.location = tr->points[0],
			.orientation = norm},
		ray, info);
	if (t == INFINITY)
		return (INFINITY);
	return (triangle_inside(tr, norm, ray_point(ray, t))
			? t : INFINITY);
}
