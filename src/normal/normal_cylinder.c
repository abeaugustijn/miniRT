/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:33:17 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/03 16:04:45 by aaugusti         ###   ########.fr       */
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
	return (rayres.normal);
}
