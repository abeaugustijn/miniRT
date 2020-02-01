/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/01 14:47:35 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres		obj_dist_sphere(t_object *sp, t_ray ray)
{
	/*t_vec3f		closest;*/
	/*double		dist_hit;*/
	/*double		radius;*/
	/*double		y;*/
	/*double		center_dist;*/

	/*if(point_line_closest(ray, sp->location, &closest))*/
		/*return (rayres_inf());*/
	/*center_dist = vec_dist(closest, sp->location);*/
	/*radius = sp->size / 2.0;*/
	/*if (center_dist > radius)*/
		/*return (rayres_inf());*/
	/*y = sqrt(pow(radius, 2) - pow(center_dist, 2));*/
	/*dist_hit = vec_dist(ray.origin, sp->location) - y;*/
	/*return (rayres_new_dist(sp,*/
				/*vec_add(ray.origin, vec_multiply(ray.direction, dist_hit)),*/
				/*sp->color, dist_hit));*/
	double t = vec_dotp(vec_sub(sp->location, ray.origin), ray.direction);
	if (t < 0)
		return (rayres_inf());
	t_vec3f p = vec_add(ray.origin, vec_multiply(ray.direction, t));

	double y = vec_len(vec_sub(sp->location, p));
	if (y > sp->size / 2)
		return (rayres_inf());
	double x = sqrt(pow(sp->size / 2, 2) - pow(y, 2));
	return (rayres_new_dist(
				sp, vec_sub(p, vec_multiply(ray.direction, x)), sp->color, t - x));
}

