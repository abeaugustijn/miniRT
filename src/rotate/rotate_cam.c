/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_cam.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/16 22:26:19 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/14 09:34:24 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "rotate.h"

void	rotate_cam(int keycode, t_info *info)
{
	t_move_dir	axis;
	double		factor;
	bool		increase;

	rotate_get_dir(keycode, &axis, &increase);
	factor = MOVE_SPEED * M_PI / 10.0 * (increase ? 1 : -1);
	if (axis == UP)
	{
		rotate_relative(&info->current_cam->dir_vecs.forward,
				info->current_cam->dir_vecs.up, factor);
		cam_update_forward(info->current_cam);
	}
	else if (axis == RIGHT)
	{
		rotate_relative(&info->current_cam->dir_vecs.up,
				info->current_cam->dir_vecs.right, factor);
		cam_update_up(info->current_cam);
	}
	info->mapinfo.rendered = false;
}
