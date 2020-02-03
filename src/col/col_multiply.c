/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:19:07 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 16:06:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	Multiply all values of a color vector by a certain factor.
**
**	@param {t_color} color
**	@param {double} factor
**
**	@return {t_color}
*/

t_color	col_multiply(t_color color, double factor)
{
	t_color	res;

	res.r = fmin(color.r * factor, 255.0);
	res.g = fmin(color.g * factor, 255.0);
	res.b = fmin(color.b * factor, 255.0);
	return (res);
}
