/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   look_at.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 16:32:06 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 14:26:18 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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

	res.x = ray_origin.x * cam->dir_vecs.right.x + ray_origin.y *
		cam->dir_vecs.up.x + ray_origin.z * cam->dir_vecs.forward.x;
	res.y = ray_origin.x * cam->dir_vecs.right.y + ray_origin.y *
		cam->dir_vecs.up.y + ray_origin.z * cam->dir_vecs.forward.y;
	res.z = ray_origin.x * cam->dir_vecs.right.z + ray_origin.y *
		cam->dir_vecs.up.z + ray_origin.z * cam->dir_vecs.forward.z;
	return (res);
}
