/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:03:39 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/17 10:24:02 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

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
	cam->dir_vecs.forward = vec_multiply(cam->orientation, -1);
	cam->dir_vecs.right = vec_normalize(vec_crossp(base, cam->dir_vecs.forward));
	cam->dir_vecs.up = vec_normalize(vec_crossp(cam->dir_vecs.forward,
				cam->dir_vecs.right));
}
