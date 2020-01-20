/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:51:29 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/18 17:37:56 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>

	#include <stdio.h>

int	hook_close(int keycode, t_mlxinfo *mlx_info)
{
	printf("%d\n", keycode);
	if (keycode < 100)
		mlx_destroy_window(mlx_info->mlx, mlx_info->mlx_win);
	return (0);
}
