/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:33:17 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/10 11:43:17 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Get the normal vector for a plane.
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f}
*/

t_vec3f	normal_cylinder(t_rayres rayres)
{
	(void)rayres;
	return (vec_new(1, 0, 0)); //TODO
}
