/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_obj.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/16 22:20:03 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 16:45:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "rotate.h"

void	(*g_rotatejmp[])(t_object *, t_move_dir, bool, t_info *) = {
	[SP] = NULL,
	[PL] = &rotate_plane,
	[SQ] = &rotate_square,
	[CY] = &rotate_plane,
	[TR] = NULL,
	[DS] = &rotate_plane,
};

/*
**	Rotate an object in respect to their own orientation (or forward) vector.
**
**	@param {t_object *} obj
**	@param {t_move_dir} axis
**	@param {bool} increase - true if the rotation should be increased
**	@param {t_info *} info
*/

void	rotate_obj(int keycode, t_info *info)
{
	bool		increase;
	t_move_dir	axis;

	rotate_get_dir(keycode, &axis, &increase);
	if (g_rotatejmp[info->selected->type])
		g_rotatejmp[info->selected->type](info->selected, axis, increase,
				info);
	info->mapinfo.rendered = false;
}
