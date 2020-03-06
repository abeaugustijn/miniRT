/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:42:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/06 11:34:38 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <math.h>

t_rayres		obj_dist_triangle(t_object *tr, t_ray ray, t_info *info)
{
	t_rayres	pl_res;
	t_object	pl;

	ft_bzero(&pl, sizeof(t_object));
	pl.type = PL;
	pl.location = tr->points[0];
	pl.orientation = normal(rayres_new(tr, vec_new(0, 0, 0)), info);
	if (float_compare(vec_dotp(pl.orientation, ray.direction), 0))
		return (rayres_inf());
	pl_res = obj_dist(&pl, ray, info);
	if (pl_res.dist == INFINITY)
		return (rayres_inf());
	if (!triangle_inside(tr, pl.orientation, pl_res.p))
		return (rayres_inf());
	return (rayres_new_dist(tr, pl_res.p, vec_dist(ray.origin, pl_res.p)));
}

