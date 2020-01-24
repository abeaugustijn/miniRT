/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_mix_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:03:41 by abe               #+#    #+#             */
/*   Updated: 2020/01/24 11:44:39 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_color	col_mix_ambient(t_color col, t_color amb)
{
	return (col_new((double)col.r * amb.r / 255,
				(double)col.g * amb.g / 255,
				(double)col.b * amb.b / 255));
}
