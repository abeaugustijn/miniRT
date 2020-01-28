/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:17:21 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/28 20:15:54 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>
#include <stdlib.h>

static void pixel_put(t_mlximg img, uint16_t x, uint16_t y, t_color color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bpp / 8));
	*(unsigned int *)dst = to_color(color);
}

int			hook_frame(t_info *info)
{
	uint16_t	i;
	uint16_t	j;

	if (info->mapinfo.rendered)
		return (0);
	info->mapinfo.rendered = true;
	i = 0;
	while (i < info->mapinfo.res.x)
	{
		j = 0;
		while (j < info->mapinfo.res.y)
		{
			pixel_put(
					info->mlx_info.img,
					i, j,
					get_pixel((t_vec2i){i, j}, info));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->mlx_info.mlx, info->mlx_info.mlx_win,
			info->mlx_info.img.ptr, 0, 0);
	return (0);
}
