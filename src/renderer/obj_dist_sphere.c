/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/21 23:26:08 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

double		obj_dist_sphere(t_object *sp, t_ray ray, t_color *color)
{
	t_vec3f	closest;
	double	ray_dist;
	double	radius;
	double	y;

	if(point_line_closest(ray, sp->location, &closest))
		return (INFINITY);
	ray_dist = vec_dist(closest, sp->location);
	radius = sp->size / 2.0;
	if (ray_dist > radius)
		return (INFINITY);
	y = sqrt(pow(radius, 2) - pow(ray_dist, 2));
	// Only temporary:
	*color = col_multiply(sp->color, y / radius);
	return (vec_dist(closest, ray.origin) - y);
}

