/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/04 17:42:51 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

#define T_CY (closest[0])
#define T_RAY (closest[1])
#define P_CY (points[0])
#define P_RAY (points[1])

static double	find_x(t_object *cy, t_ray ray, double dist, double *delta)
{
	double	dotp;
	double	angle;
	double	x_temp;
	double	x;

	dotp = vec_dotp(cy->orientation, ray.direction);
	if (dotp < 0)
		dotp *= -1.0;
	angle = acos(dotp);
	/*if (angle >= M_PI / 2)*/
		/*angle -= M_PI / 2;*/
	angle = M_PI / 2 - angle;
	x_temp = cy->size / 2 / cos(angle);
	x = sqrt(pow(cy->size / 2, 2) - pow(dist, 2)) / (cy->size / 2);
	x *= x_temp;
	*delta = x * dotp;
	return (x);
}

t_rayres		obj_dist_cylinder(t_object *cy, t_ray ray, t_info *info)
{
	double		dist;
	double		closest[2];
	double		x;
	double		delta;
	t_vec3f		points[2];
	t_vec3f		p;

	(void)info;
	points_line_closest(ray_new(cy->location, cy->orientation), ray, closest);
	if (T_RAY < 0)
		return (rayres_inf());
	P_CY = vec_add(cy->location, vec_multiply(cy->orientation, closest[0]));
	P_RAY = ray_point(ray, T_RAY);
	dist = vec_dist(P_CY, P_RAY);
	x = find_x(cy, ray, dist, &delta);
	if (dist > cy->size / 2 || vec_dist(P_CY, cy->location) > cy->height / 2 + delta)
		return (rayres_inf());
	p = ray_point(ray, T_RAY - x);
	return (rayres_new_normal(cy, p, cy->color, T_RAY - x,
				vec_from_to(P_CY, p)));
}
