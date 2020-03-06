/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rot_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:37:30 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/06 17:40:06 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <key_codes.h>
#include <math.h>

#define CAM info->current_cam

void	key_rot_cam(int keycode, t_info *info)
{
	t_vec4f	quat;

	info->mapinfo.rendered = false;
	if (keycode == KEY_LEFT)
		quat = quat_rot(CAM->orientation, CAM->dir_vecs.up,
				MOVE_SPEED / 10.0 * M_PI);
	else if (keycode == KEY_RIGHT)
		quat = quat_rot(CAM->orientation, CAM->dir_vecs.up,
				-MOVE_SPEED / 10.0 * M_PI);
	else
		info->mapinfo.rendered = true;
	if (info->mapinfo.rendered)
		return ;
	CAM->orientation = vec_multiply(quat_to_vec3(quat), 1);
	cam_update(CAM);
}
