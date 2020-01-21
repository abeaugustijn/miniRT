/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:17:21 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/21 21:41:24 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>
#include <stdlib.h>

int	hook_frame(t_info *info)
{
	t_color		*frame;
	uint16_t	i;
	uint16_t	j;

	if (info->mapinfo.rendered)
		return (0);
	info->mapinfo.rendered = true;
	frame = get_frame(info);
	i = 0;
	while (i < info->mapinfo.res.x)
	{
		j = 0;
		while (j < info->mapinfo.res.y)
		{
			mlx_pixel_put(
					info->mlx_info.mlx,
					info->mlx_info.mlx_win,
					i, j,
					to_color(frame[info->mapinfo.res.y * i + j]));
			j++;
		}
		i++;
	}
	free(frame);
	return (0);
}
