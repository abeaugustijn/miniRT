/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   col_mix.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 10:03:41 by abe           #+#   #+#                  */
/*   Updated: 2020/02/03 16:04:38 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Mix two colors by taking the average.
**
**	@param {t_color} col1
**	@param {t_color} col2
**
**	@return {t_color}
*/

t_color	col_mix(t_color col1, t_color col2)
{
	return (col_new(col1.r / 2 + col2.r / 2,
				col1.g / 2 + col2.g / 2,
				col1.b / 2 + col2.b / 2));
}
