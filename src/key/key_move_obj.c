/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:00:02 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/09 13:52:22 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <key_codes.h>

static t_move_dir	get_move_dir(int keycode)
{
	if (keycode == KEY_OBJ_UP)
		return (UP);
	if (keycode == KEY_OBJ_DOWN)
		return (DOWN);
	if (keycode == KEY_OBJ_RIGHT)
		return (RIGHT);
	if (keycode == KEY_OBJ_LEFT)
		return (LEFT);
	if (keycode == KEY_OBJ_FORWARD)
		return (FORWARD);
	if (keycode == KEY_OBJ_BACK)
		return (BACK);
	return (42);
}

void				key_move_obj(int keycode, t_info *info)
{
	if (!info->selected)
		return ;
	move(info->selected, get_move_dir(keycode), info);
	info->mapinfo.rendered = false;
}
