/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_add_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:18:46 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/07 14:29:50 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Add a color to an already existing surface color like natural light would.
**	This means it adds all elements of a color to the original color by taking
**	the max value of the two.
**
**	@param {t_color} a
**	@param {t_color} b
**
**	@return {t_color}
*/

t_color	col_add_light(t_color a, t_color b)
{
	return (col_new(max(a.r, b.r),
				max(a.g, b.g),
				max(a.b, b.b)));
}

