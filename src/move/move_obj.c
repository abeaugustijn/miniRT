/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_obj.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:28:46 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 14:17:54 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <key_codes.h>
#include <minirt.h>
#include "move.h"

static t_move_dir	get_move_dir(int keycode)
{
	if (keycode == KEY_MOVE_UP)
		return (UP);
	if (keycode == KEY_MOVE_DOWN)
		return (DOWN);
	if (keycode == KEY_MOVE_RIGHT)
		return (RIGHT);
	if (keycode == KEY_MOVE_LEFT)
		return (LEFT);
	if (keycode == KEY_MOVE_FORWARD)
		return (FORWARD);
	if (keycode == KEY_MOVE_BACK)
		return (BACK);
	return (42);
}

/*
**	Move an object in the space.
**
**	@param {int} keycode
**	@param {t_info *} info
*/

void				move_obj(int keycode, t_info *info)
{
	g_movejmp[info->selected->type](info->selected,
			get_move_dir(keycode), info);
	info->mapinfo.rendered = false;
}
