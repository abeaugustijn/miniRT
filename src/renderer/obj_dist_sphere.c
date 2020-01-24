/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/24 16:21:12 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

double		obj_dist_sphere(t_object *sp, t_ray ray, t_color *color,
		t_info *info)
{
	t_vec3f	closest;
	double	ray_dist;
	double	radius;
	/*double	y;*/

	if(point_line_closest(ray, sp->location, &closest))
		return (INFINITY);
	ray_dist = vec_dist(closest, sp->location);
	radius = sp->size / 2.0;
	if (ray_dist > radius)
		return (INFINITY);
	/*y = sqrt(pow(radius, 2) - pow(ray_dist, 2));*/
	// Only temporary:
	/**color = col_multiply(sp->color, y / radius);*/
	*color = col_multiply(col_mix_ambient(sp->color, info->mapinfo.ambient_color), info->mapinfo.ambient_ratio);
	/*return (vec_dist(closest, ray.origin) - y);*/
	return (vec_dist(closest, ray.origin));
}

