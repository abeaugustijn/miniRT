/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_square.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/16 22:49:22 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 16:47:02 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "../update/update.h"

void	rotate_square(t_object *sq, t_move_dir axis, bool increase,
			t_info *info)
{
	double	factor;
	t_vec3f	direction;

	factor = MOVE_SPEED * M_PI / 10.0 * (increase ? 1 : -1);
	if (axis == FORWARD)
	{
		rotate_relative(&sq->dir_vecs.up, sq->dir_vecs.forward, factor);
		sq->dir_vecs.right = vec_normalize(vec_crossp(sq->dir_vecs.up,
					sq->dir_vecs.forward));
	}
	else
	{
		direction = axis == UP ? sq->dir_vecs.up : sq->dir_vecs.right;
		rotate_relative(&sq->dir_vecs.forward, direction, factor);
		update_dir_vecs(&sq->dir_vecs);
	}
	children_square_update(sq, info);
}
