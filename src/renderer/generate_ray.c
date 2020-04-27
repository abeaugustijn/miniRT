/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_ray.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:43:01 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/08 20:59:49 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <minirt.h>

/*
**	Generate a ray for the given pixel on the screen.
**
**	@param {t_vec2i} pixel
**	@param {t_info *} info
**
**	@return {t_ray}
*/

t_ray	generate_ray(t_vec2i pixel, t_info *info)
{
	double	fov_factor;
	t_ray	ray;

	fov_factor = tan(info->current_cam->fov / 2 * (M_PI / 180));
	ray.origin = vec_new(
		(2 * (pixel.x + 0.5) / info->mapinfo.res.x - 1) * fov_factor,
		(1 - 2 * (pixel.y + 0.5) / info->mapinfo.res.y) * fov_factor,
		-1);
	if (info->mapinfo.res.x > info->mapinfo.res.y)
		ray.origin.x *= info->mapinfo.res.x / (double)info->mapinfo.res.y;
	else
		ray.origin.y *= info->mapinfo.res.y / (double)info->mapinfo.res.x;
	ray.origin = look_at(info->current_cam, ray.origin);
	ray.origin = vec_add(ray.origin, info->current_cam->location);
	ray.direction = vec_from_to(info->current_cam->location, ray.origin);
	ray.origin = info->current_cam->location;
	return (ray);
}
