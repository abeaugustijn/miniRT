/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:55:27 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/11 20:50:03 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>
#include <stdlib.h>
#include <keys.h>
#include <math.h>

/*
**	The hook function executed on every keypress.
**
**	TODO: used for debugging atm
**
**	@param {t_info *} info
**
**	@return {int} (not used}
*/

#include <stdio.h>

int	hook_key(int keycode, t_info *info)
{
	t_camera *cam;

	cam = info->current_cam;
	printf("%d\n", keycode);
	if (keycode == KEY_SPACE || keycode == KEY_Q)
	{
		mlx_destroy_window(info->mlx_info.mlx, info->mlx_info.mlx_win);
		exit(0);
	}
	info->mapinfo.rendered = false;
	if (keycode == KEY_H)
		cam->location = vec_add(cam->location, vec_multiply(vec_rot_y(cam->orientation, M_PI / 2), -MOVE_SPEED));
	else if (keycode == KEY_J)
		cam->location = vec_add(cam->location, vec_multiply(vec_rot_x(cam->orientation, M_PI / 2), -MOVE_SPEED));
	else if (keycode == KEY_K)
		cam->location = vec_add(cam->location, vec_multiply(vec_rot_x(cam->orientation, M_PI / 2), MOVE_SPEED));
	else if (keycode == KEY_L)
		cam->location = vec_add(cam->location, vec_multiply(vec_rot_y(cam->orientation, M_PI / 2), MOVE_SPEED));
	else if (keycode == KEY_UP)
		cam->location = vec_sub(cam->location, vec_multiply(cam->orientation, MOVE_SPEED));
	else if (keycode == KEY_DOWN)
		cam->location = vec_add(cam->location, vec_multiply(cam->orientation, MOVE_SPEED));
	else if (keycode == KEY_LEFT)
		cam->orientation = vec_normalize(vec_rot_y(cam->orientation, -MOVE_SPEED / 10.0 * M_PI));
	else if (keycode == KEY_RIGHT)
		cam->orientation = vec_normalize(vec_rot_y(cam->orientation, MOVE_SPEED / 10.0 * M_PI));
	else
		info->mapinfo.rendered = true;
	return (0);
}
