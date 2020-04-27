/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_dir_vecs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 15:25:40 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 14:24:43 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <minirt.h>

/*
**	Gets the axis the camera is looking at.
**
**	@param {t_vec3f} cam_dir
**
**	@return {t_vec3f} axis
*/

static t_vec3f	get_axis(t_vec3f cam_dir)
{
	if (fabs(cam_dir.x) >= fabs(cam_dir.y) &&
			fabs(cam_dir.x) >= fabs(cam_dir.z))
		return (vec_new(1, 0, 0));
	else if (fabs(cam_dir.y) > fabs(cam_dir.z))
		return (vec_new(0, 1, 0));
	else
		return (vec_new(0, 0, 1));
}

/*
**	Generate the direction vectors for moving an object. This will take the
**	direction of the camera into account.
**
**	@param {t_vec3f} cam_dir
**	@param {t_vec3f} obj_forward - this is what is considered the objects own
**		forward vector.
**
**	@return {t_dir_vecs}
*/

t_dir_vecs		get_dir_vecs(t_vec3f cam_dir)
{
	t_dir_vecs	res;
	t_vec3f		base;

	res.forward = get_axis(cam_dir);
	if (vec_angle(res.forward, cam_dir) < M_PI_2)
		res.forward = vec_multiply(res.forward, -1);
	if (float_compare(fabs(res.forward.y), 1))
	{
		res.right = vec_new((res.forward.y > 0) ? 1 : -1, 0, 0);
		res.up = vec_new(0, 0, (res.forward.y > 0) ? -1 : 1);
	}
	else
	{
		base = vec_new(0, 1, 0);
		res.right = vec_normalize(vec_crossp(base, res.forward));
		res.up = vec_normalize(vec_crossp(res.forward, res.right));
	}
	return (res);
}
