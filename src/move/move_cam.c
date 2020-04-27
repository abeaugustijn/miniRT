/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_cam.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/16 20:42:07 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 14:17:29 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <key_codes.h>
#include <minirt.h>

/*
**	Move the current camera.
**
**	@param {int} keycode
**	@param {t_info *} info
*/

void			move_cam(int keycode, t_info *info)
{
	int		factor;
	t_vec3f	direction;

	factor = ((keycode == KEY_MOVE_BACK || keycode == KEY_MOVE_RIGHT ||
			keycode == KEY_MOVE_UP) ? 1 : -1) * MOVE_SPEED;
	if (keycode == KEY_MOVE_FORWARD || keycode == KEY_MOVE_BACK)
		direction = info->current_cam->dir_vecs.forward;
	else
		direction = (keycode == KEY_MOVE_RIGHT || keycode == KEY_MOVE_LEFT) ?
			info->current_cam->dir_vecs.right : info->current_cam->dir_vecs.up;
	info->current_cam->location = vec_add(info->current_cam->location,
				vec_multiply(direction, factor));
	info->mapinfo.rendered = false;
}
