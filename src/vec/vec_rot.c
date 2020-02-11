/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:27:28 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/11 15:32:46 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	Rotate a vector around the x axis
**
**	@param {t_vec3f} vec
**	@param {double} rad
**
**	@return {t_vec3f}
*/

t_vec3f	vec_rot_x(t_vec3f vec, double rad)
{
	return (vec_new(vec.x,
				vec.y * cos(rad) - vec.z * sin(rad),
				vec.y * sin(rad) + vec.z * cos(rad)));
}

/*
**	Rotate a vector around the y axis
**
**	@param {t_vec3f} vec
**	@param {double} rad
**
**	@return {t_vec3f}
*/

t_vec3f	vec_rot_y(t_vec3f vec, double rad)
{
	return (vec_new(vec.x * cos(rad) + vec.z * sin(rad),
				vec.y,
				-vec.x * sin(rad) + vec.z * cos(rad)));
}

/*
**	Rotate a vector around the z axis
**
**	@param {t_vec3f} vec
**	@param {double} rad
**
**	@return {t_vec3f}
*/

t_vec3f	vec_rot_z(t_vec3f vec, double rad)
{
	return (vec_new(vec.x * cos(rad) - vec.y * sin(rad),
				vec.x * sin(rad) + vec.y * cos(rad),
				vec.z));
}
