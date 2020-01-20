/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:51:29 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/20 15:24:26 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>
#include <stdlib.h>

	#include <stdio.h>

int	hook_close(int keycode, t_mlxinfo *mlx_info)
{
	printf("%d\n", keycode);
	if (keycode > 100)
		return (0);
	mlx_destroy_window(mlx_info->mlx, mlx_info->mlx_win);
	exit(0);
	return (0);
}
