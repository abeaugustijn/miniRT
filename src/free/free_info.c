/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_info.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 20:31:31 by abe           #+#   #+#                  */
/*   Updated: 2020/04/14 09:58:30 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>
#include <mlx.h>

/*
**	Frees all the information in the given info struct.
**
**	@param {t_info *} info
*/

void	free_info(t_info *info)
{
	free(info->cameras.vla);
	free(info->objects.vla);
	free(info->lights.vla);
	free(info->current_line);
	if (info->mlx_info.img.ptr)
		mlx_destroy_image(info->mlx_info.mlx, info->mlx_info.img.ptr);
	if (info->mlx_info.mlx_win)
		mlx_destroy_window(info->mlx_info.mlx, info->mlx_info.mlx_win);
}
