/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:55:17 by abe               #+#    #+#             */
/*   Updated: 2020/03/05 18:55:42 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H
# include <miniRT.h>

double	intersect_plane(t_object *pl, t_ray ray, t_info *info);
double	intersect_sphere(t_object *sp, t_ray ray, t_info *info);
double	intersect_square(t_object *sp, t_ray ray, t_info *info);
double	intersect_cylinder(t_object *cy, t_ray ray, t_info *info);
double	intersect_triangle(t_object *tr, t_ray ray, t_info *info);
double	intersect_disk(t_object *ds, t_ray ray, t_info *info);

double	(*g_intersectjump[])(t_object *, t_ray, t_info *) = {
	&intersect_sphere,
	&intersect_plane,
	&intersect_square,
	&intersect_cylinder,
	&intersect_triangle,
	&intersect_disk,
};

#endif
