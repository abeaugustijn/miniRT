/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:59:43 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/24 13:39:26 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

#define CAM info->current_cam

t_rayres		obj_dist_plane(t_object *pl, t_ray ray, t_info *info)
{
	t_rayres	res;

	(void)info;
	res.dist = vec_dotp(vec_sub(pl->location, CAM->location), pl->orientation) /
		vec_dotp(ray.direction, pl->orientation);
	if (res.dist < 0)
		return (rayres_inf());
	if (float_compare(vec_dotp(ray.direction, pl->orientation), 0))
		return (rayres_inf());
	res.color = pl->color;
	res.p = vec_add(CAM->location, vec_multiply(ray.direction, res.dist));
	res.obj = pl;
	return (res);
}

