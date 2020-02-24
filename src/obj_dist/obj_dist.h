/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:50:24 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/24 12:36:18 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_DIST_H
# define OBJ_DIST_H

# include <miniRT.h>

t_rayres		obj_dist_sphere(t_object *sp, t_ray ray, t_info *info);
t_rayres		obj_dist_plane(t_object *pl, t_ray ray, t_info *info);
t_rayres		obj_dist_cylinder(t_object *cy, t_ray ray, t_info *info);
t_rayres		obj_dist_triangle(t_object *tr, t_ray ray, t_info *info);
t_rayres		obj_dist_disk(t_object *ds, t_ray ray, t_info *info);

t_rayres		(*g_objdistjump[])(t_object *, t_ray, t_info *) = {
	&obj_dist_sphere,
	&obj_dist_plane,
	NULL,
	&obj_dist_cylinder,
	&obj_dist_triangle,
	&obj_dist_disk,
};

#endif
