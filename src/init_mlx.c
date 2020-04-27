/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 13:16:52 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 12:26:14 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <mlx.h>
#include <stdbool.h>

static bool	init_mlx_img(t_info *info)
{
	info->mlx_info.img.ptr = mlx_new_image(info->mlx_info.mlx,
			info->mapinfo.res.x, info->mapinfo.res.y);
	if (!info->mlx_info.img.ptr)
		return (true);
	info->mlx_info.img.addr = mlx_get_data_addr(info->mlx_info.img.ptr,
			&info->mlx_info.img.bpp, &info->mlx_info.img.line_length,
			&info->mlx_info.img.endian);
	if (!info->mlx_info.img.addr)
		return (true);
	return (false);
}

static int	exit_hook(t_info *info)
{
	exit_clean(info);
	return (0);
}

bool		init_mlx(t_info *info)
{
	info->mlx_info.mlx = mlx_init();
	if (!info->mlx_info.mlx)
		return (true);
	info->mlx_info.mlx_win = mlx_new_window(info->mlx_info.mlx,
			info->mapinfo.res.x, info->mapinfo.res.y, WINDOW_TITLE);
	if (!info->mlx_info.mlx_win)
		return (true);
	if (init_mlx_img(info))
		return (true);
	mlx_hook(info->mlx_info.mlx_win, 17, 0L, &exit_hook, info);
	mlx_key_hook(info->mlx_info.mlx_win, &hook_key, info);
	mlx_mouse_hook(info->mlx_info.mlx_win, &hook_mouse, info);
	mlx_loop_hook(info->mlx_info.mlx, &hook_frame, info);
	return (false);
}
