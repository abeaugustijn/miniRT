/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:32:06 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/11 17:18:02 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

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
	t_vec3f	forward;
	t_vec3f	right;
	t_vec3f	up;

	forward = cam->orientation;
	right = vec_crossp(vec_new(0, 1, 0), forward);
	up = vec_crossp(forward, right);
	return (vec_new(
		right.x * ray_origin.x + right.y * ray_origin.y + right.z * ray_origin.z,
		up.x * ray_origin.x + up.y * ray_origin.y + up.z * ray_origin.z,
		forward.x * ray_origin.x + forward.y * ray_origin.y + forward.z * ray_origin.z));
}
