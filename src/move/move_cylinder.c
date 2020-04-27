/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_cylinder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:20:20 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/09 17:44:01 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	move_cylinder(t_object *cy, t_move_dir move_dir, t_info *info)
{
	t_vec3f	dir;

	dir = move_get_dir(move_dir, get_dir_vecs(info->current_cam->orientation));
	cy->location = vec_add(cy->location, dir);
	children_cylinder_update(cy, info);
}
