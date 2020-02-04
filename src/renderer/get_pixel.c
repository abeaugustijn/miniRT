/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:36:58 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/04 14:33:52 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	Get the color of a certain pixel on the screen. This function generates
**	a ray for the given pixel and casts it by calling 'ray_cast' with the
**	generated ray. 
**
**	@param {t_vec2i} pixel - should be valid values, otherwise undefined be-
**		haviour will occur.
**	@param {t_info *} info
**
**	@return {t_color}
*/

t_color			get_pixel(t_vec2i pixel, t_info *info)
{
	t_ray		ray;
	t_vec3f		cam_loc;
	double		fov_factor;

	fov_factor = tan(info->current_cam->fov / 2 * (M_PI / 180));
	cam_loc = info->current_cam->location;
	ray.origin.x = (2 * ((pixel.x + 0.5) / info->mapinfo.res.x) - 1)  * fov_factor;
	ray.origin.y = (1 - (2 *((pixel.y + 0.5) / info->mapinfo.res.y))) * fov_factor;
	ray.origin.z = -1;
	// TODO: Do rotation on ray.origin according to camera orientation
	ray.origin = vec_add(ray.origin, cam_loc);
	if (info->mapinfo.res.x > info->mapinfo.res.y)
		ray.origin.x *= info->mapinfo.res.x / (double)info->mapinfo.res.y;
	else
		ray.origin.y *= info->mapinfo.res.y / (double)info->mapinfo.res.x;
	ray.direction = vec_from_to(cam_loc, ray.origin);
	return (ray_cast(info, ray));
}
