/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:55:27 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/21 16:31:53 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>
#include <stdlib.h>

	#include <stdio.h>

int	hook_key(int keycode, t_info *info)
{
	printf("keypress: %d\n", keycode);
	if (keycode == 49 || keycode == 12)
	{
		mlx_destroy_window(info->mlx_info.mlx, info->mlx_info.mlx_win);
		exit(0);
	}
	info->mapinfo.rendered = false;
	if (keycode == 4)
		info->current_cam->location.x -= MOVE_SPEED;
	else if (keycode == 38)
		info->current_cam->location.y -= MOVE_SPEED;
	else if (keycode == 40)
		info->current_cam->location.y += MOVE_SPEED;
	else if (keycode == 37)
		info->current_cam->location.x += MOVE_SPEED;
	else if (keycode == 126)
		info->current_cam->location.z += MOVE_SPEED * 10;
	else if (keycode == 125)
		info->current_cam->location.z -= MOVE_SPEED * 10;
	else
		info->mapinfo.rendered = true;
	return (0);
}
