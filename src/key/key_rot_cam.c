/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rot_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:37:30 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/13 11:05:07 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <key_codes.h>
#include <math.h>

void	key_rot_cam(int keycode, t_info *info)
{
	t_vec4f	quat;
	t_camera *cam;
	double	speed;

	cam = info->current_cam;
	speed = MOVE_SPEED / 10.0 * M_PI;
	if (keycode == KEY_LEFT)
		quat = quat_rot(cam->orientation, cam->dir_vecs.up, speed);
	else if (keycode == KEY_RIGHT)
		quat = quat_rot(cam->orientation, cam->dir_vecs.up, -speed);
	else if (keycode == KEY_S)
		quat = quat_rot(cam->orientation, cam->dir_vecs.right, -speed);
	else
		quat = quat_rot(cam->orientation, cam->dir_vecs.right, speed);
	cam->orientation = vec_normalize(quat_to_vec3(quat));
	cam_update(cam);
	info->mapinfo.rendered = false;
}
