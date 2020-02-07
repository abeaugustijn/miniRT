/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/07 17:53:18 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	This function calculates the point on the ray which is closest to the
**	center of the cylinder.
**
**	@param {t_object *} cy
**	@param {t_ray} ray
**	@param {t_vec3f} ray_to_cy - a normalized from the ray origin to the
**		position of the cylinder.
**
**	@return {t_vec3f} //TODO: maybe return t?
*/

static t_vec3f	get_closest_ray(t_object *cy, t_ray ray, t_vec3f ray_to_cy)
{
	double	t;

	t = (vec_dotp(ray.direction, ray_to_cy) * vec_dotp(cy->orientation, cy->orientation)
			- vec_dotp(ray.direction, cy->orientation) * vec_dotp(cy->orientation, ray_to_cy)) / 
		(vec_dotp(ray.direction, ray.direction) * vec_dotp(cy->orientation, cy->orientation)
		 	- pow(vec_dotp(ray.direction, cy->orientation), 2));
	return (vec_add(ray.origin, vec_multiply(ray.direction, t)));
}


/*
**	This function calculates the point on the cylinder which is closest to the
**	ray.
**
**	@param {t_vec3f} cy
**	@param {t_ray} ray
**	@param {t_vec3f} ray_to_cy - a normalized from the ray origin to the
**		position of the cylinder.
**
**	@return {t_vec3f} //TODO: maybe return t?
*/

static t_vec3f	get_closest_cy(t_object *cy, t_ray ray, t_vec3f ray_to_cy)
{
	double	t;

	t = (vec_dotp(ray.direction, cy->orientation) * vec_dotp(ray.direction, ray_to_cy)
			- vec_dotp(cy->orientation, ray_to_cy) * vec_dotp(ray.direction, ray.direction)) / 
		(vec_dotp(ray.direction, ray.direction) * vec_dotp(cy->orientation, cy->orientation)
		 	- pow(vec_dotp(ray.direction, cy->orientation), 2));
	return (vec_add(cy->location, vec_multiply(cy->orientation, t)));
}

t_rayres		obj_dist_cylinder(t_object *cy, t_ray ray)
{
	t_vec3f ray_to_cy;
	t_vec3f	p_ray;
	t_vec3f	p_cy;
	double	dist;

	ray_to_cy = vec_from_to(ray.origin, cy->location);
	p_ray = get_closest_ray(cy, ray, ray_to_cy);
	p_cy = get_closest_cy(cy, ray, ray_to_cy);
	dist = vec_dist(p_ray, p_cy);
	if (dist > cy->size / 2 || vec_dist(p_cy, cy->location) > cy->size / 2)
		return (rayres_inf());
	return (rayres_new_dist(cy, p_cy, cy->color, vec_dist(ray.origin, p_cy)));
}

