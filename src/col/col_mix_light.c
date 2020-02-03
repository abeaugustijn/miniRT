/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_mix_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:03:41 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 16:06:06 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Generate the color that a colored surface will reflect when a certain color
**	of light falls on it.
**
**	@param {t_color} col - the color of the surface
**	@param {t_color} light - the light color
**
**	@return {t_color}
*/

t_color	col_mix_light(t_color col, t_color light)
{
	return (col_new((double)col.r * light.r / 255,
				(double)col.g * light.g / 255,
				(double)col.b * light.b / 255));
}
