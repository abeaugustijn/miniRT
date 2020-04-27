/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_cam_cycle.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 15:01:15 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/06 17:57:01 by abe           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <key_codes.h>

void			key_cam_cycle(int keycode, t_info *info)
{
	int		new_i;

	if (info->cameras.size == 1)
		return ;
	new_i = info->current_cam_i + (keycode == KEY_E ? 1 : -1);
	if (new_i == (int)info->cameras.size)
		new_i = 0;
	if (new_i < 0)
		new_i = info->cameras.size - 1;
	info->current_cam_i = new_i;
	vla_get_addr(info->cameras, new_i, (void **)&info->current_cam);
	info->mapinfo.rendered = false;
}
