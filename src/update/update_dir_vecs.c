/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_dir_vecs.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 10:24:42 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 16:50:44 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

void	update_dir_vecs(t_dir_vecs *vecs)
{
	if (float_compare(fabs(vecs->forward.y), 1))
		vecs->forward = vec_normalize(vec_new(
				vecs->forward.x, vecs->forward.y, vecs->forward.z + EPSILON));
	vecs->right = vec_normalize(vec_crossp(vec_new(0, 1, 0), vecs->forward));
	vecs->up = vec_normalize(vec_crossp(vecs->forward, vecs->right));
}
