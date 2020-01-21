/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:36:58 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/21 12:29:27 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_color			get_pixel(t_vec2i pixel, t_info *info)
{
	t_ray	ray;
	double	ar;
	double	fov_factor;

	if (info->mapinfo.res.x > info->mapinfo.res.y)
		ar = info->mapinfo.res.x / info->mapinfo.res.y;
	else
		ar = info->mapinfo.res.y / info->mapinfo.res.x;
	fov_factor = tan(info->current_cam->fov / 2 * M_PI / 180);
	ray.origin.x = (2 * ((pixel.x + 0.5) / info->mapinfo.res.x - 1)) * ar * fov_factor;
	ray.origin.y = (1 - 2 *((pixel.y + 0.5) / info->mapinfo.res.y)) * fov_factor;
	ray.origin.z = info->current_cam->location.z - 1;
	ray_calc_dir(&ray, info->current_cam->location);
	return (ray_cast(info, ray));
}
