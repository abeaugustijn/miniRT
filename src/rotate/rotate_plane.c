/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_plane.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 19:11:56 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 16:46:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	rotate_plane(t_object *pl, t_move_dir axis, bool increase,
			t_info *info)
{
	t_vec3f	direction;
	double	factor;

	if (axis == FORWARD)
		return ;
	factor = MOVE_SPEED * M_PI / 10.0 * (increase ? 1 : -1);
	direction = axis == UP ? pl->dir_vecs.up : pl->dir_vecs.right;
	rotate_relative(&pl->dir_vecs.forward, direction, factor);
	update(pl, info);
}
