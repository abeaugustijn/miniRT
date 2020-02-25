/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:32:06 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/25 17:12:11 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

#define D cam->dir_vecs

/*
**	Translate the origin of a given ray according to the orientation of the
**	camera.
**
**	@param {t_camera *} cam
**	@param {t_vec3f} ray_origin
**
**	@return {t_vec3f} - new origin
*/

t_vec3f	look_at(t_camera *cam, t_vec3f ray_origin)
{
	t_vec3f	res;

	res.x = ray_origin.x * D.right.x + ray_origin.y * D.up.x + ray_origin.z * D.forward.x;
	res.y = ray_origin.x * D.right.y + ray_origin.y * D.up.y + ray_origin.z * D.forward.y;
	res.z = ray_origin.x * D.right.z + ray_origin.y * D.up.z + ray_origin.z * D.forward.z;
	return (res);
}
