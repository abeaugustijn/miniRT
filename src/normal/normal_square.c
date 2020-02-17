/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:53:29 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/17 14:30:10 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "normal.h"

/*
**	Gets the normal vector of a square.
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f} normal
*/

t_vec3f	normal_square(t_rayres rayres, t_info *info)
{
	t_object	*children[2];

	find_children(rayres.obj, children, info);
	rayres.obj = children[0];
	return (normal_triangle(rayres, info));
}
