/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/16 22:40:07 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/08 20:10:08 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <key_codes.h>
#include <minirt.h>

void	key_rotate(int keycode, t_info *info)
{
	if ((keycode == KEY_ROT_FORWARD_PLUS || keycode == KEY_ROT_FORWARD_MINUS)
			&& !info->selected)
		return ;
	(info->selected ? rotate_obj : rotate_cam)(keycode, info);
}
