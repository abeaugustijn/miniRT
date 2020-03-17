/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 10:16:34 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/17 10:46:59 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "update.h"

/*
**	Update an object to account for new position or rotation in space. This
**	update properties like the direction vectors and children.
**
**	@param {t_object *} obj
**	@param {t_info *} info
*/

void	(*g_updatejmp[])(t_object *, t_info *) = {
	[SP] = NULL,
	[PL] = &update_plane,
	[SQ] = &update_square,
	[CY] = &update_cylinder,
	[TR] = NULL,
	[DS] = &update_disk,
};

void	update(t_object *obj, t_info *info)
{
	if (g_updatejmp[obj->type])
		g_updatejmp[obj->type](obj, info);
}
