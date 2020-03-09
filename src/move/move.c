/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:28:46 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/09 14:33:30 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "move.h"

/*
**	Move an object in the space.
**
**	@param {t_object *} obj
**	@param {t_move_dir} move_dir
**	@param {t_info *} info
*/

void	move(t_object *obj, t_move_dir move_dir, t_info *info)
{
	g_movejmp[obj->type](obj, move_dir, info);
}
