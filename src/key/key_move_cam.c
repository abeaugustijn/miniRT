/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:35:28 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/24 20:54:49 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <key_codes.h>
#include <math.h>

#define CAM info->current_cam

void	key_move_cam(int keycode, t_info *info)
{
	t_vec3f	up;
	t_vec3f	right;
	t_vec3f	base;
	t_vec3f	forward;

	if (float_compare(CAM->orientation.y, 1))
		base = vec_new(1, 0, 0);
	else
		base = vec_new(0, 1, 0);
	forward = vec_multiply(CAM->orientation, -1);
	right = vec_normalize(vec_crossp(base, forward));
	up = vec_normalize(vec_crossp(forward, right));
	info->mapinfo.rendered = false;
	if (keycode == KEY_UP)
		CAM->location = vec_add(CAM->location, vec_multiply(CAM->orientation, MOVE_SPEED));
	else if (keycode == KEY_DOWN)
		CAM->location = vec_add(CAM->location, vec_multiply(CAM->orientation, -MOVE_SPEED));
	else if (keycode == KEY_H)
		CAM->location = vec_add(CAM->location, vec_multiply(right, -MOVE_SPEED));
	else if (keycode == KEY_J)
		CAM->location = vec_add(CAM->location, vec_multiply(up, -MOVE_SPEED));
	else if (keycode == KEY_K)
		CAM->location = vec_add(CAM->location, vec_multiply(up, MOVE_SPEED));
	else if (keycode == KEY_L)
		CAM->location = vec_add(CAM->location, vec_multiply(right, MOVE_SPEED));
	else
		info->mapinfo.rendered = true;
}
