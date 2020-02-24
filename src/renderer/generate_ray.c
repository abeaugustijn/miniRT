/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:43:01 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/24 19:36:06 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

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
	t_ray	ray;
	t_vec3f	cam_loc;
	double	fov_factor;

	fov_factor = tan(info->current_cam->fov / 2 * (M_PI / 180));
	cam_loc = info->current_cam->location;
	ray.origin = vec_new(
		(2 * ((pixel.x + 0.5) / info->mapinfo.res.x) - 1)  * fov_factor,
		(1 - (2 *((pixel.y + 0.5) / info->mapinfo.res.y))) * fov_factor,
		1);
	ray.origin = look_at(info->current_cam, ray.origin);
	ray.origin = vec_add(ray.origin, cam_loc);
	if (info->mapinfo.res.x > info->mapinfo.res.y)
		ray.origin.x *= info->mapinfo.res.x / (double)info->mapinfo.res.y;
	else
		ray.origin.y *= info->mapinfo.res.y / (double)info->mapinfo.res.x;
	ray.direction = vec_from_to(cam_loc, ray.origin);
	return (ray);
}
