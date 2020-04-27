/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_key.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 15:55:27 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/14 15:01:10 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	The hook function executed on every keypress.
**
**	@param {t_info *} info
**
**	@return {int} (not used}
*/

int	hook_key(int keycode, t_info *info)
{
	key(keycode, info);
	return (0);
}
