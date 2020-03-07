/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:15:53 by abe               #+#    #+#             */
/*   Updated: 2020/03/07 16:30:51 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	This fixes the normal vector for when the vector of 'flat' objects is
**	calculated. This makes sure the normal always faces the ray origin.
**
**	@param {t_rayres} rayres
**	@param {t_ray} ray
**	@param {t_vec3f *} norm
*/

void		fix_normal(t_vec3f ray_direction, t_vec3f *norm)
{
	if (vec_angle(*norm, ray_direction) < M_PI / 2)
		*norm = vec_multiply(*norm, -1);
}

