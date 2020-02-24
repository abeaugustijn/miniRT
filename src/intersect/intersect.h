/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:55:17 by abe               #+#    #+#             */
/*   Updated: 2020/02/24 12:30:04 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H
# include <miniRT.h>

bool	intersect_plane(t_object *pl, t_ray ray, t_info *info);
bool	intersect_sphere(t_object *sp, t_ray ray, t_info *info);
bool	intersect_square(t_object *sp, t_ray ray, t_info *info);
bool	intersect_cylinder(t_object *cy, t_ray ray, t_info *info);
bool	intersect_triangle(t_object *tr, t_ray ray, t_info *info);
bool	intersect_disk(t_object *ds, t_ray ray, t_info *info);

bool	(*g_intersectjump[])(t_object *, t_ray, t_info *) = {
	&intersect_sphere,
	&intersect_plane,
	&intersect_square,
	&intersect_cylinder,
	&intersect_triangle,
	&intersect_disk,
};

#endif
