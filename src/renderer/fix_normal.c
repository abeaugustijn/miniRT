/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fix_normal.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 20:15:53 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 14:21:07 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

/*
**	This fixes the normal vector for when the vector of 'flat' objects is
**	calculated. This makes sure the normal always faces the ray origin.
**
**	@param {t_vec3f} ray_direction
**	@param {t_vec3f} normal
**
**	@return {t_vec3f}
*/

inline t_vec3f	fix_normal(t_vec3f ray_direction, t_vec3f normal)
{
	if (vec_angle(normal, ray_direction) < M_PI_2)
		return (vec_multiply(normal, -1));
	return (normal);
}
