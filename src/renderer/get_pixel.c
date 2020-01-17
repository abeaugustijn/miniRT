/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:36:58 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/17 17:14:03 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	Converts a pixel to a normalized vector in respect to the screen dimensions.
**
**	@param {t_vec2i} pixel - the pixel on the screen. Both sould be in range of
**		the resolution.
**	@param {t_vec2i} res - a vector containing the screen resolution
**
**	@return {
*/

static t_vec2f	get_pixel_ndc(t_vec2i pixel, t_vec2i res)
{
	t_vec2f	result;

	result.x = (pixel.x + 0.5) / res.x;
	result.y = (pixel.y + 0.5) / res.y;
	return (result);
}

/*
**	Converts a normalized vector representing a place in a screen to a pixel
**	in the screen.
**
**	@param {t_vec2f} pixel_ndc
**	@param {t_vec2i} res
**
**	@return {t_vec2f}
*/

static t_vec2f	get_pixel_screen(t_vec2f pixel_ndc, t_vec2i res)
{
	t_vec2f	result;
	double	ar;

	if (res.x > res.y)
		ar = res.x / res.y;
	else
		ar = res.y / res.x;
	result.x = (2 * pixel_ndc.x - 1) * ar;
	result.y = 1 - 2 * pixel_ndc.y;
	return (result);
}

static t_vec2f	get_pixel_fov(t_vec2f pixel_screen, uint8_t fov)
{
	t_vec2f	result;
	double	factor;

	factor = tan(fov / 2);
	result.x = pixel_screen.x * factor;
	result.y = pixel_screen.y * factor;
	return (result);
}

t_color			get_pixel(t_vec2i pixel, t_info *info)
{
	t_color	res;
	t_vec2f	pixel_ndc;
	t_vec2f	pixel_screen;
	t_vec2f pixel_fov;
	t_vec3f pixel_camspace;

	pixel_ndc = get_pixel_ndc(pixel, info->mapinfo.res);
	pixel_screen = get_pixel_screen(pixel_ndc, info->mapinfo.res);
	pixel_fov = get_pixel_fov(pixel_screen, info->current_cam->fov);
	pixel_camspace.x = info->current_cam->location.x + pixel_fov.x;
	pixel_camspace.y = info->current_cam->location.y + pixel_fov.y;
	pixel_camspace.z = info->current_cam->location.z - 1;
	res.r = 0;
	res.g = 0;
	res.b = 0;
	return (res);
}
