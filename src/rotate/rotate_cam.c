/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:26:19 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/16 23:00:06 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "rotate.h"

void	rotate_cam(int keycode, t_info *info)
{
	t_move_dir	axis;
	t_vec3f		direction;
	double		factor;
	bool		increase;

	rotate_get_dir(keycode, &axis, &increase);
	if (axis == FORWARD)
		return ;
	direction = axis == UP ? info->current_cam->dir_vecs.up
		: info->current_cam->dir_vecs.right;
	factor = MOVE_SPEED * M_PI / 10.0 * (increase ? 1 : -1);
	info->current_cam->orientation = vec_normalize(quat_to_vec3(quat_rot(
					info->current_cam->orientation, direction, factor)));
	cam_update(info->current_cam);
	info->mapinfo.rendered = false;
}
