/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fix_dir_vecs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 15:17:16 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/09 15:19:46 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

/*
**	Invert some firection vectors to take camera location into account.
**
**	@param {t_vec3f} cam_direction
**	@param {t_dir_vecs} dir_vecs
**
**	@return {t_dir_vecs}
*/

t_dir_vecs	fix_dir_vecs(t_vec3f cam_direction, t_dir_vecs dir_vecs)
{
	t_dir_vecs	res;

	res = dir_vecs;
	if (vec_angle(cam_direction, dir_vecs.forward) < M_PI_2)
	{
		res.forward = vec_multiply(res.forward, -1);
		res.right = vec_multiply(res.right, -1);
	}
	return (res);
}
