/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_len.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 16:23:26 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/06 16:24:17 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

double	quat_len(t_vec4f quat)
{
	return (sqrt(
		pow(quat.w, 2) +
		pow(quat.x, 2) +
		pow(quat.y, 2) +
		pow(quat.z, 2)));
}
