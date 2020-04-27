/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_normalize.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 16:21:33 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/06 16:23:06 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec4f	quat_normalize(t_vec4f quat)
{
	double	len;

	len = quat_len(quat);
	return ((t_vec4f){
			.w = quat.w / len,
			.x = quat.x / len,
			.y = quat.y / len,
			.z = quat.z / len});
}
