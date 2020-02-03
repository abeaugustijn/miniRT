/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:40:56 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 16:20:04 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Get the normal vector for a plane. (spoiler alert: its just the orientation
**	of the plane).
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f}
*/

t_vec3f	normal_plane(t_rayres rayres)
{
	return (rayres.obj->orientation);
}
