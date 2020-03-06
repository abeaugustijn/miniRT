/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:55:27 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/06 11:20:42 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libftprintf.h>

/*
**	The hook function executed on every keypress.
**
**	TODO: used for debugging atm
**
**	@param {t_info *} info
**
**	@return {int} (not used}
*/

#include <stdio.h>

int	hook_key(int keycode, t_info *info)
{
	ft_printf("%d\n", keycode);
	key(keycode, info);
	return (0);
}
