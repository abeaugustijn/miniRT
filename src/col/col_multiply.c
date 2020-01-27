/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:19:07 by abe               #+#    #+#             */
/*   Updated: 2020/01/21 22:22:11 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_color	col_multiply(t_color color, double factor)
{
	t_color	res;

	res.r = fmin(color.r * factor, 255.0);
	res.g = fmin(color.g * factor, 255.0);
	res.b = fmin(color.b * factor, 255.0);
	return (res);
}
