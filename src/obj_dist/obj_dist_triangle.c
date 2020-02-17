/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:42:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/17 16:34:31 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <math.h>

t_rayres		obj_dist_triangle(t_object *tr, t_ray ray, t_info *info)
{
	t_rayres	pl_res;
	t_vec3f		tr_normal;
	t_object	pl;

	ft_bzero(&pl, sizeof(t_object));
	pl.type = PL;
	pl.location = tr->points[0];
	tr_normal = normal(rayres_new(tr, vec_new(0, 0, 0), col_new(0, 0, 0)), info);
	if (float_compare(vec_dotp(tr_normal, ray.direction), 0))
		return (rayres_inf());
	pl.orientation = tr_normal;
	pl_res = obj_dist(&pl, ray, info);
	if (pl_res.dist >= INFINITY)
		return (rayres_inf());
	if (!triangle_inside(tr, tr_normal, pl_res.p))
		return (rayres_inf());
	return (rayres_new_dist(tr, pl_res.p, tr->color, vec_dist(ray.origin, pl_res.p)));
}

