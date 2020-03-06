/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:01 by abe               #+#    #+#             */
/*   Updated: 2020/03/06 08:52:15 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	Calculate whether a given ray intersects with a cylinder.
**
**	@param {t_object *} cy (cylinder)
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {double}
*/

double	intersect_cylinder(t_object *cy, t_ray ray, t_info *info)
{
	(void)cy;
	(void)ray;
	(void)info;
	return (INFINITY); //TODO
}
