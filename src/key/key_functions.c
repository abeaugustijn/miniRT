/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:48:59 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/18 14:50:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "key_functions.h"

void	key(int keycode, t_info *info)
{
	uint8_t	i;

	i = 0;
	while (g_keyjump[i].func)
	{
		if (g_keyjump[i].key == keycode)
		{
			g_keyjump[i].func(keycode, info);
			return ;
		}
		i++;
	}
}
