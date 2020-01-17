/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:17:21 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/17 17:12:30 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>

int	hook_frame(t_info *info)
{
	t_vec2i	pixel;

	if (!info->mapinfo.rendered)
	{
		info->mapinfo.rendered = true;
		for (uint16_t i = 0; i < info->mapinfo.res.x; i++)
			for (uint16_t j = 0; j < info->mapinfo.res.y; j++)
			{
				pixel.x = i;
				pixel.y = j;
				mlx_pixel_put(
						info->mlx_info.mlx,
						info->mlx_info.mlx_win,
						i, j,
						to_color(get_pixel(pixel, info)));
			}
	}
	return (0);
}
