/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_disk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:20:20 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/09 14:33:10 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	move_disk(t_object *ds, t_move_dir move_dir, t_info *info)
{
	t_vec3f	dir;

	(void)info;
	dir = move_get_dir(move_dir, ds->dir_vecs);
	ds->location = vec_add(ds->location, dir);
}
