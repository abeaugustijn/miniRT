/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:35:28 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/25 16:07:56 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <key_codes.h>
#include <math.h>

#define CAM info->current_cam

void	key_move_cam(int keycode, t_info *info)
{
	info->mapinfo.rendered = false;
	if (keycode == KEY_UP)
		CAM->location = vec_add(CAM->location, vec_multiply(CAM->orientation,
					MOVE_SPEED));
	else if (keycode == KEY_DOWN)
		CAM->location = vec_add(CAM->location, vec_multiply(CAM->orientation,
					-MOVE_SPEED));
	else if (keycode == KEY_H)
		CAM->location = vec_add(CAM->location, vec_multiply(CAM->dir_vecs.right,
					-MOVE_SPEED));
	else if (keycode == KEY_J)
		CAM->location = vec_add(CAM->location, vec_multiply(CAM->dir_vecs.up,
					-MOVE_SPEED));
	else if (keycode == KEY_K)
		CAM->location = vec_add(CAM->location, vec_multiply(CAM->dir_vecs.up,
					MOVE_SPEED));
	else if (keycode == KEY_L)
		CAM->location = vec_add(CAM->location, vec_multiply(CAM->dir_vecs.right,
					MOVE_SPEED));
	else
		info->mapinfo.rendered = true;
}
