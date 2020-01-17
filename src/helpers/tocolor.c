/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tocolor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:03:14 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/17 15:04:39 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	to_color(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}