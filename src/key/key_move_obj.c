/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:00:02 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/06 14:57:11 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <key_codes.h>

#define LOC (info->selected->location)
#define DIRS (info->current_cam->dir_vecs)

static void	update(t_object *obj, t_info *info)
{
	if (obj->type == SQ)
		children_square_update(obj, info);
	if (obj->type == CY)
		children_cylinder_update(obj, info);
}

void	key_move_obj(int keycode, t_info *info)
{
	if (!info->selected)
		return ;
	if (keycode == KEY_OBJ_RIGHT)
		LOC = vec_add(LOC, vec_multiply(DIRS.right, MOVE_SPEED));
	if (keycode == KEY_OBJ_LEFT)
		LOC = vec_add(LOC, vec_multiply(DIRS.right, -MOVE_SPEED));
	if (keycode == KEY_OBJ_UP)
		LOC = vec_add(LOC, vec_multiply(DIRS.up, -MOVE_SPEED));
	if (keycode == KEY_OBJ_DOWN)
		LOC = vec_add(LOC, vec_multiply(DIRS.up, MOVE_SPEED));
	if (keycode == KEY_OBJ_FORWARD)
		LOC = vec_add(LOC, vec_multiply(DIRS.forward, -MOVE_SPEED));
	if (keycode == KEY_OBJ_BACK)
		LOC = vec_add(LOC, vec_multiply(DIRS.forward, MOVE_SPEED));
	update(info->selected, info);
	info->mapinfo.rendered = false;
}
