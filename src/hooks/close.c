/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:51:29 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/17 13:55:19 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>

	#include <stdio.h>

int	hook_close(int keycode, t_mlxinfo *mlx_info)
{
	printf("%d\n", keycode);
	mlx_destroy_window(mlx_info->mlx, mlx_info->mlx_win);
	return (0);
}
