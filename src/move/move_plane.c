/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_plane.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:44:41 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/09 17:40:09 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

void	move_plane(t_object *pl, t_move_dir move_dir, t_info *info)
{
	t_vec3f	dir;

	dir = move_get_dir(move_dir, get_dir_vecs(info->current_cam->orientation));
	pl->location = vec_add(pl->location, dir);
}
