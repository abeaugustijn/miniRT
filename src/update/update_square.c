/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_square.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 10:32:40 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 16:51:40 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "update.h"

void	update_square(t_object *sq, t_info *info)
{
	update_dir_vecs(&sq->dir_vecs);
	children_square_update(sq, info);
}
