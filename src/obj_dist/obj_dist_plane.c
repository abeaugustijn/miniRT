/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:59:43 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/03 16:31:45 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres		obj_dist_plane(t_object *pl, t_ray ray, t_info *info)
{
	double		dist;

	(void)info;
	dist = vec_dotp(vec_sub(pl->location, ray.origin), pl->orientation) /
		vec_dotp(ray.direction, pl->orientation);
	if (dist < 0)
		return (rayres_inf());
	if (float_compare(vec_dotp(ray.direction, pl->orientation), 0))
		return (rayres_inf());
	return (rayres_new_dist(pl, vec_add(ray.origin,
					vec_multiply(ray.direction, dist)), pl->color, dist));
}

