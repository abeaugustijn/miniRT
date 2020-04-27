/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_sphere.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:36:15 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/09 16:06:05 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	move_sphere(t_object *sp, t_move_dir move_dir, t_info *info)
{
	t_vec3f	dir;

	dir = move_get_dir(move_dir, get_dir_vecs(info->current_cam->orientation));
	sp->location = vec_add(sp->location, dir);
}
