/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 10:16:34 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 16:49:56 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "update.h"

void	(*g_updatejmp[])(t_object *, t_info *) = {
	[SP] = NULL,
	[PL] = &update_plane,
	[SQ] = &update_square,
	[CY] = &update_cylinder,
	[TR] = NULL,
	[DS] = &update_disk,
};

/*
**	Update an object to account for new position or rotation in space. This
**	update properties like the direction vectors and children.
**
**	@param {t_object *} obj
**	@param {t_info *} info
*/

void	update(t_object *obj, t_info *info)
{
	if (g_updatejmp[obj->type])
		g_updatejmp[obj->type](obj, info);
}
