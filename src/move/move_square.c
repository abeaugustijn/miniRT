/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_square.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:56:08 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/09 15:50:36 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	move_square(t_object *sq, t_move_dir move_dir, t_info *info)
{
	t_vec3f	dir;

	(void)info;
	dir = move_get_dir(move_dir,
			get_dir_vecs(info->current_cam->orientation));
	sq->location = vec_add(sq->location, dir);
	children_square_update(sq, info);
}
