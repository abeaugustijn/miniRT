/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/21 14:59:02 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
 
static bool	does_intersect(t_object *sp, t_ray ray)
{
	double	ray_dist;

	ray_dist = dist_line_point(ray, sp->location);
	return (ray_dist < sp->size / 2);
}

double		obj_dist_sphere(t_object *sp, t_ray ray)
{
	double	dist_to_center;

	(void)dist_to_center;
	if (!does_intersect(sp, ray))
		return (INFINITY);
	return (1);
}

