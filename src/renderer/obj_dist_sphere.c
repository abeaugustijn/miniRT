/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/04 16:35:50 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres		obj_dist_sphere(t_object *sp, t_ray ray)
{
	double	t;
	double	y;
	double	x;
	t_vec3f	p;

	t = vec_dotp(vec_sub(sp->location, ray.origin), ray.direction);
	if (t < 0)
		return (rayres_inf());
	p = vec_add(ray.origin, vec_multiply(ray.direction, t));
	y = vec_len(vec_sub(sp->location, p));
	if (y > sp->size / 2)
		return (rayres_inf());
	x = sqrt(pow(sp->size / 2, 2) - pow(y, 2));
	return (rayres_new_dist(
				sp, vec_sub(p, vec_multiply(ray.direction, x)), sp->color, t - x));
}

