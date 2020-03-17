/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:01 by abe               #+#    #+#             */
/*   Updated: 2020/03/17 10:03:13 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

#define T_CY (closest[0])
#define T_RAY (closest[1])
#define P_CY (points[0])
#define P_RAY (points[1])

/*
**	Calculate the point on the cylinders axis which is closest to the hitpoint.
**
**	@param {t_object *cy}
**	@param {t_vec3f} p - hitpoint
**
**	@return {t_vec3f}
*/

static t_vec3f	get_closest_p(t_object *cy, t_vec3f p)
{
	double	delta_s;

	delta_s = vec_dotp(vec_sub(p, cy->location), cy->dir_vecs.forward) /
		vec_dotp(cy->dir_vecs.forward, cy->dir_vecs.forward);
	return(vec_add(cy->location, vec_multiply(cy->dir_vecs.forward, delta_s)));
}

/*
**	Calculate the distance from P_RAY to the point where the ray actually
**	hit the cylinder. Two factors will need to be calculated, x_angle and
**	x_circle. Respectively, these represent the extra distance for the ray
**	hitting the cylinder at an angle and the value accounting for the rounding
**	of the cylinder. The delta value is also calculated in this function. This
**	represents the 'extra height' the cylinder has because of a ray hitting
**	it at an angle.
**
**	@param {t_object *} cy
**	@param {t_ray} ray
**	@param {double} dist - the distance from P_CY to P_RAY
**	@param {double *} delta
**
**	@return {double} the length from P_CY to the hitpoint (in the direction of
**		the ray)
*/

static double	find_x(t_object *cy, t_ray ray, double dist, double *delta)
{
	double	angle;
	double	dotp;
	double	x_angle;
	double	x_circle;

	dotp = vec_dotp(cy->dir_vecs.forward, ray.direction);
	if (dotp < 0)
		dotp *= -1.0;
	angle = acos(dotp);
	angle = M_PI / 2 - angle;
	x_angle = cy->size / 2 / cos(angle);
	x_circle = sqrt(pow(cy->size / 2, 2) - pow(dist, 2)) / (cy->size / 2);
	x_circle *= x_angle;
	*delta = x_circle * dotp;
	return (x_circle);
}

static bool		look_in(t_object *cy, double *dist, t_vec3f *p,
		t_vec3f *p_on_cy, t_ray ray, double *closest)
{
	if (vec_dist(cy->location, *p_on_cy) < cy->height / 2)
		return(false);
	*dist *= -1;
	*p = ray_point(ray, *dist + T_RAY);
	*p_on_cy = get_closest_p(cy, *p);
	if (vec_dist(cy->location, *p_on_cy) > cy->height / 2)
		return(true);
	return (false);
}

	#include <assert.h>

double			intersect_cylinder(t_object *cy, t_ray ray, t_vec3f *normal,
					t_info *info)
{
	double		closest[2];
	double		dist;
	double		delta;
	t_vec3f		p;
	t_vec3f		p_on_cy;
	t_vec3f		points[2];
	double		x;

	(void)info;
	points_line_closest(ray_new(cy->location, cy->dir_vecs.forward), ray, closest);
	P_CY = vec_add(cy->location, vec_multiply(cy->dir_vecs.forward, closest[0]));
	P_RAY = ray_point(ray, T_RAY);
	dist = vec_dist(P_CY, P_RAY);
	x = find_x(cy, ray, dist, &delta);
	if (T_RAY < -x ||
			dist > cy->size / 2 ||
			fabs(T_CY) > cy->height / 2 + delta)
		return (INFINITY);
	dist = (x > T_RAY) ? x : -x;
	p = ray_point(ray, dist + T_RAY);
	p_on_cy = get_closest_p(cy, p);
	if (look_in(cy, &dist, &p, &p_on_cy, ray, closest))
		return (INFINITY);
	if (normal)
		*normal = vec_from_to(p_on_cy, p);
	assert(vec_dist(p_on_cy, cy->location) <= cy->height / 2);
	assert(vec_dist(p, cy->location) <= sqrt(pow(cy->height / 2, 2) + pow(cy->size / 2, 2)));
	return (dist + T_RAY);
}
