/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_disk.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:20:20 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/10 09:25:12 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	move_disk(t_object *ds, t_move_dir move_dir, t_info *info)
{
	t_vec3f	dir;

	(void)info;
	dir = move_get_dir(move_dir, get_dir_vecs(info->current_cam->orientation));
	ds->location = vec_add(ds->location, dir);
}
