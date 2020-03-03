/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/03 16:19:02 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres		obj_dist_cylinder(t_object *cy, t_ray ray, t_info *info)
{
	double		dist;
	double		closest[2];
	double		x;
	t_vec3f		points[2];
	t_vec3f		p;

	(void)info;
	if (float_compare(pow(vec_dotp(ray.direction, cy->orientation), 2),
				vec_dotp(ray.direction, ray.direction) * vec_dotp(cy->orientation, cy->orientation)))
		return (rayres_inf());
	points_line_closest(ray_new(cy->location, cy->orientation), ray, closest);
	if (closest[1] < 0)
		return (rayres_inf());
	points[0] = vec_add(cy->location, vec_multiply(cy->orientation, closest[0]));
	points[1] = vec_add(ray.origin, vec_multiply(ray.direction, closest[1]));
	dist = vec_dist(points[0], points[1]);
	if (dist > cy->size / 2 || vec_dist(points[0], cy->location) > cy->height / 2)
		return (rayres_inf());
	x = sqrt(pow(cy->size / 2, 2) - pow(dist, 2));
	p = vec_add(ray.origin, vec_multiply(ray.direction, closest[1] - x));
	return (rayres_new_normal(cy, p, cy->color, closest[1] - x, vec_from_to(points[0], p)));
}
