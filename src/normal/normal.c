/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:33:58 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 16:19:19 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "normal.h"

/*
**	Get the normal vector of an object on the place where a ray hit it. Uses
**	a jumptable to determine the right function for the object.
**
**	@param {t_rayres} rayres - this contains a pointer to the object and the
**		coordinates of the point where the ray hit the object.
**
**	@return {t_vec3f}
*/

t_vec3f	normal(t_rayres rayres)
{
	return (g_normaljump[rayres.obj->type](rayres));
}
