/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tocolor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:03:14 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/03 16:14:13 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Convert a color struct to an integer that mlx can read.
**
**	@param {t_color} color
**
**	@return {int}
*/

int	to_color(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}
