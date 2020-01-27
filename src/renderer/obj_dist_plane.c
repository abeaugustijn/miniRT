/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:59:43 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/27 15:59:45 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres		obj_dist_plane(t_object *pl, t_ray ray)
{
	t_rayres	res;

	res.dist = vec_dotp(vec_sub(pl->location, ray.origin), pl->orientation) /
		vec_dotp(ray.direction, pl->orientation);
	res.color = pl->color;
	return (res);
}

