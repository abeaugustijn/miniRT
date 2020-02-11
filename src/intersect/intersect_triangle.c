/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:01 by abe               #+#    #+#             */
/*   Updated: 2020/02/11 12:15:53 by aaugusti         ###   ########.fr       */
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
**
**	@return {bool} - true if intersect
*/

bool	intersect_triangle(t_object *tr, t_ray ray)
{
	t_rayres	pl_res;
	t_vec3f		tr_normal;
	t_object	pl;

	ft_bzero(&pl, sizeof(t_object));
	pl.type = PL;
	pl.location = tr->points[0];
	tr_normal = normal(rayres_new(tr, vec_new(0, 0, 0), col_new(0, 0, 0)));
	if (float_compare(vec_dotp(tr_normal, ray.direction), 0))
		return (false);
	pl.orientation = tr_normal;
	pl_res = obj_dist(&pl, ray);
	if (pl_res.dist >= INFINITY)
		return (false);
	if (!triangle_inside(tr, tr_normal, pl_res.p))
		return (false);
	return (true);
}
