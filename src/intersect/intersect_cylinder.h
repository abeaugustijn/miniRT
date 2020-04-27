/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 20:11:47 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/07 20:17:26 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_CYLINDER_H
# define INTERSECT_CYLINDER_H

# include <minirt.h>

/*
**	A struct for storing the data used for the calculations in the
**	intersect_cylinder function.
*/

struct s_int_cy_data {
	double		delta;
	double		dist;
	double		t_cy;
	double		t_ray;
	double		x;
	t_object	*cy;
	t_ray		cy_ray;
	t_ray		ray;
	t_vec3f		p;
	t_vec3f		p_cy;
	t_vec3f		p_on_cy;
	t_vec3f		p_ray;
};

#endif
