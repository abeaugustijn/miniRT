/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/28 12:25:00 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres		obj_dist_sphere(t_object *sp, t_ray ray)
{
	t_vec3f		closest;
	double		dist_hit;
	double		radius;
	double		y;
	double		center_dist;

	if(point_line_closest(ray, sp->location, &closest))
		return (rayres_inf());
	center_dist = vec_dist(closest, sp->location);
	radius = sp->size / 2.0;
	if (center_dist > radius)
		return (rayres_inf());
	y = sqrt(pow(radius, 2) - pow(center_dist, 2));
	dist_hit = vec_dist(ray.origin, sp->location) - y;
	/*p = vec_add(ray.origin, sp->location);*/
	/*p = vec_add(p, vec_multiply(ray.direction, y));*/
	/*return (rayres_new_dist(p, sp->color, vec_dist(ray.origin, p)));*/
	return (rayres_new_dist(
				vec_add(ray.origin, vec_multiply(ray.direction, dist_hit)),
				sp->color, dist_hit));
}

