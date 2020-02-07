/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:01 by abe               #+#    #+#             */
/*   Updated: 2020/02/07 11:52:38 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Calculate whether a given ray intersects with a sphere.
**
**	@param {t_object *} sp (sphere)
**	@param {t_ray} ray
**
**	@return {bool} - true if intersect
*/

bool	intersect_sphere(t_object *sp, t_ray ray)
{
	double	t;
	t_vec3f	p;

	t = vec_dotp(vec_sub(sp->location, ray.origin), ray.direction);
	if (t < 0)
		return (false);
	p = vec_add(ray.origin, vec_multiply(ray.direction, t));
	if (vec_len(vec_sub(sp->location , p)) > sp->size / 2)
		return (false);
	return (true);
}
