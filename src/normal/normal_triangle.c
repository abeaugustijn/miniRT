/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:39:49 by abe               #+#    #+#             */
/*   Updated: 2020/02/24 17:10:40 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Gets the normal vector of a triangle. If the normal stored in the triangle
**	is not normalized, we assume that it was not generated yet and generate
**	it again.
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f} normal
*/

t_vec3f	normal_triangle(t_rayres rayres, t_info *info)
{
	t_vec3f	res;
	t_vec3f	ca;
	t_vec3f cb;

	(void)info;
	if (!check_normalized(rayres.obj->orientation))
	{
		ca = vec_from_to(rayres.obj->points[2], rayres.obj->points[0]);
		cb = vec_from_to(rayres.obj->points[2], rayres.obj->points[1]);
		res = vec_crossp(ca, cb);
		rayres.obj->orientation = vec_normalize(res);
	}
	return (rayres.obj->orientation);
}
