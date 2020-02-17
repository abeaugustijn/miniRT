/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:33:17 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/17 13:58:55 by aaugusti         ###   ########.fr       */
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

t_vec3f	normal_cylinder(t_rayres rayres, t_info *info)
{
	(void)rayres;
	(void)info;
	return (vec_new(1, 0, 0)); //TODO
}
