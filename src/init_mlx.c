/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:16:52 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/17 18:58:32 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>
#include <stdbool.h>

bool	init_mlx(t_mlxinfo *mlx_info, t_info *info)
{
	mlx_info->mlx = mlx_init();
	if (!mlx_info->mlx)
		return (true);
	mlx_info->mlx_win = mlx_new_window(mlx_info->mlx, info->mapinfo.res.x,
			info->mapinfo.res.y, WINDOW_TITLE);
	if (!mlx_info->mlx_win)
		return (true);
	mlx_key_hook(mlx_info->mlx_win, &hook_close, mlx_info);
	mlx_loop_hook(mlx_info->mlx, &hook_frame, info);
	return (false);
}
