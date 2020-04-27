/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_resize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 12:44:49 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/02/21 14:03:39 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <key_codes.h>

/*
**	Key hook for resizing a selected object.
**
**	@param {int} keycode
**	@param {t_info *} info
*/

void	key_resize(int keycode, t_info *info)
{
	bool	increase;

	if (!info->selected)
		return ;
	increase = keycode == KEY_PLUS;
	resize(info->selected, increase, info);
	info->mapinfo.rendered = false;
}
