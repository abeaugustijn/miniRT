/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:28:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/16 21:48:12 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mouse_codes.h>

int	hook_mouse(int button, int x, int y, t_info *info)
{
	if (button == MOUSE_LEFT)
		select_object(pixel_new(x, y), info);
	else
		info->selected = NULL;
	return (0);
}
