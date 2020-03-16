/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 20:42:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/16 21:46:39 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <key_codes.h>
#include <miniRT.h>

/*
**	Move the current camera.
**
**	@param {int} keycode
**	@param {t_info *} info
*/

void			move_cam(int keycode, t_info *info)
{
	info->mapinfo.rendered = false;
	if (keycode == KEY_MOVE_FORWARD)
		info->current_cam->location = vec_add(info->current_cam->location,
				vec_multiply(info->current_cam->orientation, MOVE_SPEED));
	else if (keycode == KEY_MOVE_BACK)
		info->current_cam->location = vec_add(info->current_cam->location,
				vec_multiply(info->current_cam->orientation, -MOVE_SPEED));
	else if (keycode == KEY_MOVE_RIGHT)
		info->current_cam->location = vec_add(info->current_cam->location,
				vec_multiply(info->current_cam->dir_vecs.right, MOVE_SPEED));
	else if (keycode == KEY_MOVE_LEFT)
		info->current_cam->location = vec_add(info->current_cam->location,
				vec_multiply(info->current_cam->dir_vecs.right, -MOVE_SPEED));
	else if (keycode == KEY_MOVE_UP)
		info->current_cam->location = vec_add(info->current_cam->location,
				vec_multiply(info->current_cam->dir_vecs.up, MOVE_SPEED));
	else if (keycode == KEY_MOVE_DOWN)
		info->current_cam->location = vec_add(info->current_cam->location,
				vec_multiply(info->current_cam->dir_vecs.up, -MOVE_SPEED));
	else
		info->mapinfo.rendered = true;
}
