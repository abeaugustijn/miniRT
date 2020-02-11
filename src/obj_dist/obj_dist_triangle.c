/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:42:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/11 11:19:50 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <math.h>

static bool		obj_dist_triangle_inside(t_object *tr, t_vec3f tr_normal, t_vec3f p)
{
	t_vec3f	edges[3];
	t_vec3f	c[3];

	edges[0] = vec_sub(tr->points[1], tr->points[0]);
	edges[1] = vec_sub(tr->points[2], tr->points[1]);
	edges[2] = vec_sub(tr->points[0], tr->points[2]);
	c[0] = vec_sub(p, tr->points[0]);
	c[1] = vec_sub(p, tr->points[1]);
	c[2] = vec_sub(p, tr->points[2]);
	return (vec_dotp(tr_normal, vec_crossp(edges[0], c[0])) > 0 &&
				vec_dotp(tr_normal, vec_crossp(edges[1], c[1])) > 0 &&
				vec_dotp(tr_normal, vec_crossp(edges[2], c[2])) > 0);
}

t_rayres		obj_dist_triangle(t_object *tr, t_ray ray)
{
	t_rayres	pl_res;
	t_vec3f		tr_normal;
	t_object	pl;

	ft_bzero(&pl, sizeof(t_object));
	pl.type = PL;
	pl.location = tr->points[0];
	tr_normal = normal(rayres_new(tr, vec_new(0, 0, 0), col_new(0, 0, 0)));
	if (float_compare(vec_dotp(tr_normal, ray.direction), 0))
		return (rayres_inf());
	pl.orientation = tr_normal;
	pl_res = obj_dist(&pl, ray);
	if (pl_res.dist >= INFINITY)
		return (rayres_inf());
	if (!obj_dist_triangle_inside(tr, tr_normal, pl_res.p))
		return (rayres_inf());
	return (rayres_new_dist(tr, pl_res.p, tr->color, vec_dist(ray.origin, pl_res.p)));
}

