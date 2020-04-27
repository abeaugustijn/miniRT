/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:49:01 by abe           #+#   #+#                  */
/*   Updated: 2020/04/08 19:18:27 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <minirt.h>

#if 0

# define T_CY (points_t[0])
# define T_RAY (points_t[1])
# define P_CY (points[0])
# define P_RAY (points[1])

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

	dotp = fabs(vec_dotp(cy->dir_vecs.forward, ray.direction));
	angle = acos(dotp);
	angle = M_PI / 2 - angle;
	x_angle = cy->size / 2 / cos(angle);
	x_circle = sqrt(pow(cy->size / 2, 2) - pow(dist, 2)) / (cy->size / 2);
	x_circle *= x_angle;
	*delta = x_circle * dotp;
	return (x_circle);
}

static bool		look_in(t_object *cy, double *dist, t_vec3f *p,
		t_vec3f *p_on_cy, t_ray ray, double *points_t)
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

double			intersect_cylinder(t_object *cy, t_ray ray, t_vec3f *normal,
					t_info *info)
{
	double		delta;
	double		dist;
	double		points_t[2];
	double		x;
	t_ray		cy_ray;
	t_vec3f		p;
	t_vec3f		p_on_cy;
	t_vec3f		points[2];

	(void)info;
	// Get the ray which represents the core of the cylinder
	cy_ray = ray_new(cy->location, cy->dir_vecs.forward);

	// Get the point_t's for the core-ray of the cylinder and the given ray.
	// The points which those t's indicate will be the points on the ray and
	// the cylinder which are closest to each other.
	points_line_closest(cy_ray, ray, points_t);

	// Generate the two points which result from that
	P_CY = ray_point(cy_ray, T_CY);
	P_RAY = ray_point(ray, T_RAY);

	// Calculate the distance between the point on the ray and the point on
	// the cylinder core.
	dist = vec_dist(P_CY, P_RAY);

	// Calculate x, which represents the distance betwee the point P_CY and the
	// point where the ray actually hit the sphere. We also get the value of
	// delta. Delta is the length which has to be added to the height of the
	// cylinder to account for the ray hitting it at an angle.
	x = find_x(cy, ray, dist, &delta);

	// The ray did not hit because the distance between the two points is
	// larger than the radius of the cylinder.
	if (dist > cy->size / 2)
		return (INFINITY);

	// The ray did not hit because the distance from the 'location' of the
	// cylinder to the point on the cylinder where it hits (fabs(T_CY)), is
	// larger than half of the height of the cylinder, plus the calculated
	// delta.
	if (fabs(T_CY) > cy->height / 2 + delta)
		return (INFINITY);

	// Dist will now be used as the distance from P_RAY to the point where the
	// ray hit the cylinder. If dist > T_RAY this means that we hit the back
	// size of the cylinder, so we invert the dist.
	dist = x;
	if (dist < T_RAY)
		dist *= -1;

	// Get the point where the ray hit the cylinder
	p = ray_point(ray, dist + T_RAY);

	// Get the point on cy_ray which is closest to p
	p_on_cy = get_closest_p(cy, p);

	// This checks whether the p_on_cy is actually on cy. Otherwise we know
	// that the ray hits the inside of the cylinder. Dist is inverted and the
	// new p and p_on_cy are calculated.
	if (look_in(cy, &dist, &p, &p_on_cy, ray, points_t))
		return (INFINITY);

	// Calculate the normal of the hitpoint
	if (normal)
		*normal = vec_from_to(p_on_cy, p);

	// In this case, the cylinder is behind the camera
	if (T_RAY < -dist)
		return (INFINITY);
	return (dist + T_RAY);
}

#else

# include "intersect_cylinder.h"
# include <libft.h>

static void		get_p_on_cy(struct s_int_cy_data *data)
{
	double	delta_s;

	delta_s = vec_dotp(vec_sub(data->p, data->cy->location),
		data->cy->dir_vecs.forward) / vec_dotp(data->cy->dir_vecs.forward,
		data->cy->dir_vecs.forward);
	data->p_on_cy = vec_add(data->cy->location,
		vec_multiply(data->cy->dir_vecs.forward, delta_s));
}

static void		get_x(struct s_int_cy_data *data)
{
	double	angle;
	double	dotp;
	double	x_angle;
	double	x_circle;

	dotp = fabs(vec_dotp(data->cy->dir_vecs.forward, data->ray.direction));
	angle = acos(dotp);
	angle = M_PI / 2 - angle;
	x_angle = data->cy->size / 2 / cos(angle);
	x_circle = sqrt(pow(data->cy->size / 2, 2)
			- pow(data->dist, 2)) /(data->cy->size / 2);
	data->x = x_circle * x_angle;
	data->delta = data->x * dotp;
}

static bool		get_p(struct s_int_cy_data *data, bool invert_dist)
{
	if (invert_dist)
		data->dist *= -1;
	data->p = ray_point(data->ray, data->dist + data->t_ray);
	get_p_on_cy(data);
	return (vec_dist(data->p_on_cy, data->cy->location)
			< data->cy->height / 2);
}

static void		init_data(struct s_int_cy_data *data, t_object *cy, t_ray ray)
{
	double	points_t[2];

	ft_bzero(data, sizeof(struct s_int_cy_data));
	data->cy = cy;
	data->ray = ray;
	data->cy_ray = ray_new(cy->location, cy->dir_vecs.forward);
	points_line_closest(data->cy_ray, ray, points_t);
	data->t_cy = points_t[0];
	data->t_ray = points_t[1];
	data->p_cy = ray_point(data->cy_ray, data->t_cy);
	data->p_ray = ray_point(ray, data->t_ray);
	data->dist = vec_dist(data->p_cy, data->p_ray);
}

double			intersect_cylinder(t_object *cy, t_ray ray, t_vec3f *normal,
					t_info *info)
{
	struct s_int_cy_data	data;

	(void)info;
	init_data(&data, cy, ray);
	get_x(&data);
	if (data.dist > cy->size / 2 ||
			fabs(data.t_cy) > cy->height / 2 + data.delta)
		return (INFINITY);
	data.dist = data.x;
	if (data.dist < data.t_ray)
		data.dist *= -1;
	if (!get_p(&data, false))
		if (!get_p(&data, true))
			return (INFINITY);
	if (data.t_ray < -data.dist)
		return (INFINITY);
	if (normal)
		*normal = vec_from_to(data.p_on_cy, data.p);
	return (data.dist + data.t_ray);
}

#endif
