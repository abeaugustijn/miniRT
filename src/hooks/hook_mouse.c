/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:28:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/21 13:54:37 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mouse_codes.h>

int	hook_mouse(int button, int x, int y, t_info *info)
{
	if (button != MOUSE_LEFT)
		return (0);
	select_object(pixel_new(x, y), info);
	return (0);
}