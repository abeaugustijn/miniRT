/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:55:17 by abe               #+#    #+#             */
/*   Updated: 2020/02/11 12:10:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H
# include <miniRT.h>

bool	intersect_plane(t_object *pl, t_ray ray);
bool	intersect_sphere(t_object *sp, t_ray ray);
bool	intersect_cylinder(t_object *cy, t_ray ray);
bool	intersect_triangle(t_object *tr, t_ray ray);

bool	(*g_intersectjump[])(t_object *, t_ray) = {
	&intersect_sphere,
	&intersect_plane,
	NULL,	//TODO SQ
	&intersect_cylinder,
	&intersect_triangle
};

#endif
