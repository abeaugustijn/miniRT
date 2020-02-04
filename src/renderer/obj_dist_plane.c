/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:59:43 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/04 12:06:19 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres		obj_dist_plane(t_object *pl, t_ray ray)
{
	t_rayres	res;
	double first, second;

	first = vec_dotp(vec_sub(pl->location, ray.origin), pl->orientation);
	second = vec_dotp(ray.direction, pl->orientation);
	res.dist = first / second;
	if (res.dist < 0)
		return (rayres_inf());
	if (float_compare(vec_dotp(ray.direction, pl->orientation), 0))
		return (rayres_inf());
	res.color = pl->color;
	res.p = vec_add(ray.origin, vec_multiply(ray.direction, res.dist));
	res.obj = pl;
	return (res);
}

