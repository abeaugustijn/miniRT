/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:36:58 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/28 22:09:53 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_color			get_pixel(t_vec2i pixel, t_info *info)
{
	t_ray		ray;
	t_vec3f		cam_loc;;
	double		fov_factor;

	fov_factor = tan(info->current_cam->fov / 2 * (M_PI / 180));
	cam_loc = info->current_cam->location;
	ray.origin.x = cam_loc.x + (2 * ((pixel.x + 0.5) / info->mapinfo.res.x) - 1)  * fov_factor;
	ray.origin.y = cam_loc.y + (1 - (2 *((pixel.y + 0.5) / info->mapinfo.res.y))) * fov_factor;
	if (info->mapinfo.res.x > info->mapinfo.res.y)
		ray.origin.x *= info->mapinfo.res.x / (double)info->mapinfo.res.y;
	else
		ray.origin.y *= info->mapinfo.res.y / (double)info->mapinfo.res.x;
	ray.origin.z = info->current_cam->location.z - 1;
	ray.direction = vec3f_normalize(vec_sub(ray.origin, info->current_cam->location));
	return (ray_cast(info, ray));
}
