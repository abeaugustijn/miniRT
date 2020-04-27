/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:55:17 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 17:12:51 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H
# include <minirt.h>

double	intersect_plane(t_object *pl, t_ray ray, t_vec3f *normal,
		t_info *info);
double	intersect_sphere(t_object *sp, t_ray ray, t_vec3f *normal,
		t_info *info);
double	intersect_square(t_object *sp, t_ray ray, t_vec3f *normal,
		t_info *info);
double	intersect_cylinder(t_object *cy, t_ray ray, t_vec3f *normal,
		t_info *info);
double	intersect_triangle(t_object *tr, t_ray ray, t_vec3f *normal,
		t_info *info);
double	intersect_disk(t_object *ds, t_ray ray, t_vec3f *normal,
		t_info *info);

double	(*g_intersectjump[])(t_object *, t_ray, t_vec3f *, t_info *) = {
	[SP] = &intersect_sphere,
	[PL] = &intersect_plane,
	[SQ] = &intersect_square,
	[CY] = &intersect_cylinder,
	[TR] = &intersect_triangle,
	[DS] = &intersect_disk,
};

#endif
