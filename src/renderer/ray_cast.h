/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_cast.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 19:25:38 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/08 19:26:34 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CAST_H
# define RAY_CAST_H

# include <minirt.h>

struct	s_ray_cast_data {
	double		dist;
	double		min_distance;
	t_object	*closest;
	t_object	*current;
	t_vec3f		normal;
	t_vec3f		normal_closest;
};

#endif
