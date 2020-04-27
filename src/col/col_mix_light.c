/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   col_mix_light.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 10:03:41 by abe           #+#   #+#                  */
/*   Updated: 2020/02/21 16:26:21 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
	return (col_new(col.r * light.r / 255,
				col.g * light.g / 255,
				col.b * light.b / 255));
}
