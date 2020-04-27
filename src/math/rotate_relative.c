/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_relative.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 11:39:43 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/17 19:07:39 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Rotate a forward vector relative to its location using quaternians.
**
**	@param {t_vec3f *} forward - pointer to the vector to rotate
**	@param {t_vec3f} direction - the axis along which the rotation does its
**		magic
**	@param {double} factor - the amount of rotation, in radians
*/

void	rotate_relative(t_vec3f *forward, t_vec3f direction, double factor)
{
	*forward =
		vec_normalize(quat_to_vec3(quat_rot(*forward, direction, factor)));
}
