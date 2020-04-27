/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_triangle.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:56:08 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 14:18:29 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	move_triangle(t_object *tr, t_move_dir move_dir, t_info *info)
{
	t_vec3f	dir;

	(void)info;
	dir = move_get_dir(move_dir, get_dir_vecs(info->current_cam->orientation));
	tr->points[0] = vec_add(tr->points[0], dir);
	tr->points[1] = vec_add(tr->points[1], dir);
	tr->points[2] = vec_add(tr->points[2], dir);
}
