/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_inverse.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 16:14:15 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/06 16:16:00 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec4f	quat_inverse(t_vec4f quat)
{
	return ((t_vec4f){.w = quat.w,
			.x = quat.x * -1,
			.y = quat.y * -1,
			.z = quat.z * -1});
}
