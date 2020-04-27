/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_resize_cylinder.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 14:52:10 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/06 11:10:36 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>
#include <key_codes.h>

/*
**	Function for specifically resizing the height of a cylinder.
**
**	@param {int} keycode
**	@param {t_info *} info
*/

void	key_resize_cylinder(int keycode, t_info *info)
{
	if (!info->selected || info->selected->type != CY)
		return ;
	info->selected->height *= pow(RESIZE_SPEED, keycode == KEY_PGUP ? 1 : -1);
	children_cylinder_update(info->selected, info);
	info->mapinfo.rendered = false;
}
