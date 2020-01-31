/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_mix_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:03:41 by abe               #+#    #+#             */
/*   Updated: 2020/01/31 12:32:44 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_color	col_mix_light(t_color col, t_color amb)
{
	return (col_new((double)col.r * amb.r / 255,
				(double)col.g * amb.g / 255,
				(double)col.b * amb.b / 255));
}
