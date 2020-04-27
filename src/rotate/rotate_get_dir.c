/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_get_dir.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti </var/spool/mail/abe>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/16 22:29:40 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/16 23:00:29 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <key_codes.h>

void	rotate_get_dir(int keycode, t_move_dir *axis, bool *increase)
{
	*increase = keycode == KEY_ROT_UP_MINUS || keycode == KEY_ROT_RIGHT_MINUS ||
			keycode == KEY_ROT_FORWARD_MINUS;
	if (keycode == KEY_ROT_UP_PLUS || keycode == KEY_ROT_UP_MINUS)
		*axis = UP;
	else
		*axis = (keycode == KEY_ROT_RIGHT_PLUS ||
				keycode == KEY_ROT_RIGHT_MINUS) ? RIGHT : FORWARD;
}
