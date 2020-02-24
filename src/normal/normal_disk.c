/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_disk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:40:56 by abe               #+#    #+#             */
/*   Updated: 2020/02/24 12:31:29 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Get the normal vector for a disk. (spoiler alert: its just the orientation
**	of the disk).
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f}
*/

t_vec3f	normal_disk(t_rayres rayres, t_info *info)
{
	(void)info;
	return (rayres.obj->orientation);
}
