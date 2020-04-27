/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tocolor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 15:03:14 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/02/21 16:28:47 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Convert a color struct to an integer that mlx can read.
**
**	@param {t_color} color
**
**	@return {int}
*/

int	to_color(t_color color)
{
	return ((uint8_t)color.r << 16 | (uint8_t)color.g << 8 | (uint8_t)color.b);
}
