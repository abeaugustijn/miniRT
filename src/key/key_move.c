/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_move.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:35:28 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/16 23:04:01 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Move either the camera or an object. If no object is selected the camera
**	will be moved by the buttons, otherwise the selected object will move.
**
**	@param {int} keycode
**	@param {t_info *} info
*/

void	key_move(int keycode, t_info *info)
{
	(info->selected ? move_obj : move_cam)(keycode, info);
}
