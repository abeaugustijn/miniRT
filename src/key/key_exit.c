/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:40:45 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/18 14:44:39 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>

void	key_exit(int keycode, t_info *info)
{
	(void)keycode;
	mlx_destroy_window(info->mlx_info.mlx, info->mlx_info.mlx_win);
	exit_clean(info);
}
