/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   col_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 10:04:15 by abe           #+#   #+#                  */
/*   Updated: 2020/02/21 16:26:47 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	col_new(float r, float g, float b)
{
	t_color	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}
