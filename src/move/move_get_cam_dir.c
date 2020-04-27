/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_get_cam_dir.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:39:11 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/09 14:00:06 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3f	move_get_dir(t_move_dir move_dir, t_dir_vecs dir_vecs)
{
	if (move_dir == UP)
		return (vec_multiply(dir_vecs.up, -MOVE_SPEED));
	else if (move_dir == DOWN)
		return (vec_multiply(dir_vecs.up, MOVE_SPEED));
	else if (move_dir == RIGHT)
		return (vec_multiply(dir_vecs.right, MOVE_SPEED));
	else if (move_dir == LEFT)
		return (vec_multiply(dir_vecs.right, -MOVE_SPEED));
	else if (move_dir == FORWARD)
		return (vec_multiply(dir_vecs.forward, -MOVE_SPEED));
	else
		return (vec_multiply(dir_vecs.forward, MOVE_SPEED));
}
