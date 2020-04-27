/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 21:35:23 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 17:13:48 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

# include <minirt.h>

t_vec3f	normal_sphere(t_rayres rayres, t_ray ray, t_info *info);
t_vec3f	normal_plane(t_rayres rayres, t_ray ray, t_info *info);
t_vec3f	normal_square(t_rayres rayres, t_ray ray, t_info *info);
t_vec3f	normal_cylinder(t_rayres rayres, t_ray ray, t_info *info);
t_vec3f	normal_triangle(t_rayres rayres, t_ray ray, t_info *info);
t_vec3f	normal_disk(t_rayres rayres, t_ray ray, t_info *info);

#endif
