/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:39:49 by abe               #+#    #+#             */
/*   Updated: 2020/02/10 15:39:32 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Gets the normal vector of a triangle.
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f} normal
*/

t_vec3f	normal_triangle(t_rayres rayres)
{
	t_vec3f	res;
	t_vec3f	ca;
	t_vec3f cb;

	ca = vec_from_to(rayres.obj->points[2], rayres.obj->points[0]);
	cb = vec_from_to(rayres.obj->points[2], rayres.obj->points[1]);
	res = vec_multiplyvec(ca, cb);
	return (vec_normalize(res));
}
