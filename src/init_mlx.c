/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:16:52 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/17 13:49:51 by aaugusti         ###   ########.fr       */
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
	mlx_info->mlx_win = mlx_new_window(mlx_info->mlx, info->mapinfo.res_x,
			info->mapinfo.res_y, WINDOW_TITLE);
	if (!mlx_info->mlx_win)
		return (true);
	return (false);
}
