/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:15:53 by abe               #+#    #+#             */
/*   Updated: 2020/02/25 20:22:39 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	This fixes the normal vector for when the vector of 'flat' objects is
**	calculated. This makes sure the normal always faces the camera.
**
**	@param {t_rayres} rayres
**	@param {t_ray} ray
**	@param {t_vec3f *} norm
*/

void		fix_normal(t_object_type obj_type, t_ray ray, t_vec3f *norm)
{
	if ((obj_type == TR ||
			obj_type == PL ||
			obj_type == DS)
			&& vec_angle(*norm, ray.direction) < M_PI / 2)
		*norm = vec_multiply(*norm, -1);
}

