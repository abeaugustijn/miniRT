/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_exit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:45 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/16 20:47:07 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	key_exit(int keycode, t_info *info)
{
	(void)keycode;
	exit_clean(info);
}
