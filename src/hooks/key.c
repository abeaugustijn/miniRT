/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:55:27 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/03 16:16:39 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>
#include <stdlib.h>
#include <keys.h>

	#include <stdio.h>

/*
**	The hook function executed on every keypress.
**
**	TODO: used for debugging atm
**
**	@param {t_info *} info
**
**	@return {int} (not used}
*/

int	hook_key(int keycode, t_info *info)
{
	printf("keypress: %d\n", keycode);
	if (keycode == KEY_SPACE || keycode == KEY_Q)
	{
		mlx_destroy_window(info->mlx_info.mlx, info->mlx_info.mlx_win);
		exit(0);
	}
	info->mapinfo.rendered = false;
	if (keycode == KEY_H)
		info->current_cam->location.x -= MOVE_SPEED;
	else if (keycode == KEY_J)
		info->current_cam->location.y -= MOVE_SPEED;
	else if (keycode == KEY_K)
		info->current_cam->location.y += MOVE_SPEED;
	else if (keycode == KEY_L)
		info->current_cam->location.x += MOVE_SPEED;
	else if (keycode == KEY_UP)
		info->current_cam->location.z -= MOVE_SPEED;
	else if (keycode == KEY_DOWN)
		info->current_cam->location.z += MOVE_SPEED;
	else
		info->mapinfo.rendered = true;
	return (0);
}
