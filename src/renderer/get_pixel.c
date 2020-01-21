/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:36:58 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/21 18:21:38 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_color			get_pixel(t_vec2i pixel, t_info *info)
{
	t_ray	ray;
	double	ar;
	double	fov_factor;

	fov_factor = tan(info->current_cam->fov / 2 * (M_PI / 180));
	ray.origin.x = info->current_cam->location.x;
	ray.origin.y = info->current_cam->location.y;
	if (info->mapinfo.res.x > info->mapinfo.res.y)
	{
		ar = ((double)info->mapinfo.res.x) / ((double)info->mapinfo.res.y);
		ray.origin.x += (2 * ((pixel.x + 0.5) / info->mapinfo.res.x - 1)) * ar * fov_factor;
		ray.origin.y += 1 - (2 *((pixel.y + 0.5) / info->mapinfo.res.y)) * fov_factor;
	}
	else
	{
		ar = ((double)info->mapinfo.res.y) / ((double)info->mapinfo.res.x);
		ray.origin.x += (2 * ((pixel.x + 0.5) / info->mapinfo.res.x - 1)) * fov_factor;
		ray.origin.y += 1 - (2 *((pixel.y + 0.5) / info->mapinfo.res.y)) * ar *fov_factor;
	}
	ray.origin.z = info->current_cam->location.z - 1;
	ray_calc_dir(&ray, info->current_cam->location);
	return (ray_cast(info, ray));
}
