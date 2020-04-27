/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_mouse.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:28:08 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/20 13:36:26 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <mouse_codes.h>

int	hook_mouse(int button, int x, int y, t_info *info)
{
	if (button == MOUSE_LEFT)
		select_object((t_vec2i){x, y}, info);
	else
		info->selected = NULL;
	return (0);
}
