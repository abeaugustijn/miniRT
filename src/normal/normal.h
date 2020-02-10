/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:35:23 by abe               #+#    #+#             */
/*   Updated: 2020/02/10 14:58:22 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

# include <miniRT.h>

t_vec3f	normal_sphere(t_rayres rayres);
t_vec3f	normal_plane(t_rayres rayres);
t_vec3f	normal_cylinder(t_rayres rayres);
t_vec3f	normal_triangle(t_rayres rayres);

t_vec3f	(*g_normaljump[])(t_rayres) = {
	&normal_sphere,
	&normal_plane,
	NULL,	//TODO SQ
	&normal_cylinder,
	&normal_triangle
};

#endif
