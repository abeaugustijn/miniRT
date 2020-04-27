/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cam_update.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 16:03:39 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/14 09:32:00 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	update_orientation(t_camera *cam)
{
	cam->orientation = vec_multiply(cam->dir_vecs.forward, -1);
}

/*
**	Update the camera when its values are changed.
**
**	@param {t_camera *} cam
*/

void	cam_update(t_camera *cam)
{
	t_vec3f	base;

	base = float_compare(cam->orientation.y, 1) ?
		vec_new(1, 0, 0) : vec_new(0, 1, 0);
	cam->dir_vecs.right =
		vec_normalize(vec_crossp(base, cam->dir_vecs.forward));
	cam->dir_vecs.up = vec_normalize(vec_crossp(cam->dir_vecs.forward,
				cam->dir_vecs.right));
	update_orientation(cam);
}

void	cam_update_forward(t_camera *cam)
{
	t_vec3f	base;

	base = float_compare(cam->dir_vecs.forward.y, -1) ?
		vec_new(1, 0, 0) : vec_new(0, 1, 0);
	cam->dir_vecs.right =
		vec_normalize(vec_crossp(base, cam->dir_vecs.forward));
	cam->dir_vecs.up =
		vec_normalize(vec_crossp(cam->dir_vecs.forward, cam->dir_vecs.right));
	update_orientation(cam);
}

void	cam_update_up(t_camera *cam)
{
	t_vec3f	base;

	base = float_compare(cam->dir_vecs.up.z, -1) ?
		vec_new(0, 0, 1) : vec_new(1, 0, 0);
	cam->dir_vecs.forward =
		vec_normalize(vec_crossp(base, cam->dir_vecs.up));
	cam->dir_vecs.right =
		vec_normalize(vec_crossp(cam->dir_vecs.up, cam->dir_vecs.forward));
	update_orientation(cam);
}
