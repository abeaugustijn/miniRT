/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:16:52 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/21 11:29:52 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>
#include <stdbool.h>

#define IMG info->mlx_info.img
#define MLX info->mlx_info

static bool	init_mlx_img(t_info *info)
{
	IMG.ptr = mlx_new_image(MLX.mlx, info->mapinfo.res.x,
			info->mapinfo.res.y);
	if (!IMG.ptr)
		return (true);
	IMG.addr = mlx_get_data_addr(IMG.ptr, &IMG.bpp, &IMG.line_length, &IMG.endian);
	if (!IMG.addr)
		return (true);
	return (false);
}

bool		init_mlx(t_info *info)
{
	MLX.mlx = mlx_init();
	if (!MLX.mlx)
		return (true);
	MLX.mlx_win = mlx_new_window(MLX.mlx, info->mapinfo.res.x,
			info->mapinfo.res.y, WINDOW_TITLE);
	if (!MLX.mlx_win)
		return (true);
	if (init_mlx_img(info))
		return (true);
	mlx_key_hook(MLX.mlx_win, &hook_key, info);
	mlx_mouse_hook(MLX.mlx_win, &hook_mouse, info);
	mlx_loop_hook(MLX.mlx, &hook_frame, info);
	return (false);
}
