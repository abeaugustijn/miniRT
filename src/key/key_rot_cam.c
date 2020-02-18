/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rot_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:37:30 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/18 14:59:06 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <key_codes.h>
#include <math.h>

#define CAM info->current_cam

void	key_rot_cam(int keycode, t_info *info)
{
	info->mapinfo.rendered = false;
	if (keycode == KEY_UP)
		CAM->location = vec_add(CAM->location, vec_multiply(CAM->orientation, MOVE_SPEED));
	else if (keycode == KEY_DOWN)
		CAM->location = vec_sub(CAM->location, vec_multiply(CAM->orientation, MOVE_SPEED));
	else if (keycode == KEY_LEFT)
		CAM->orientation = vec_normalize(vec_rot_y(CAM->orientation, MOVE_SPEED / 10.0 * M_PI));
	else if (keycode == KEY_RIGHT)
		CAM->orientation = vec_normalize(vec_rot_y(CAM->orientation, -MOVE_SPEED / 10.0 * M_PI));
	else
		info->mapinfo.rendered = true;
}
