/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:31:31 by abe               #+#    #+#             */
/*   Updated: 2020/02/24 23:04:47 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <mlx.h>

/*
**	Frees all the information in the given info struct.
**
**	@param {t_info *} info
*/

void	free_info(t_info *info)
{
	if (info->cameras)
		free_list(info->cameras, &free);
	if (info->objects)
		free_list(info->objects, &free);
	if (info->lights)
		free_list(info->lights, &free);
	if (info->mlx_info.img.ptr)
		mlx_destroy_image(info->mlx_info.mlx, info->mlx_info.img.ptr);
	if (info->mlx_info.mlx_win)
		mlx_destroy_window(info->mlx_info.mlx, info->mlx_info.mlx_win);
}
