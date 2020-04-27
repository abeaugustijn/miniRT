/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_rot_local.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 16:09:15 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/06 16:12:33 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

t_vec4f	quat_rot_local(t_vec3f rot_dir, double angle)
{
	return ((t_vec4f){
		.w = cos(angle / 2),
		.x = rot_dir.x * sin(angle / 2),
		.y = rot_dir.y * sin(angle / 2),
		.z = rot_dir.z * sin(angle / 2)});
}
