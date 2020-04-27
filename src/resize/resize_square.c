/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resize_square.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 13:59:36 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/02/21 14:02:51 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

void	resize_square(t_object *sq, bool increase, t_info *info)
{
	sq->size *= pow(RESIZE_SPEED, increase ? 1 : -1);
	children_square_update(sq, info);
}
