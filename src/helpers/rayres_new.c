/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayres_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:38:55 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/06 11:33:09 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_rayres	rayres_new(t_object *obj, t_vec3f p)
{
	t_rayres	res;

	res.obj = obj;
	res.p = p;
	res.dist = 0;
	res.normal = vec_new(0, 0, 0);
	return (res);
}

t_rayres	rayres_new_dist(t_object *obj, t_vec3f p, double dist)
{
	t_rayres	res;

	res.obj = obj;
	res.p = p;
	res.dist = dist;
	res.normal = vec_new(0, 0, 0);
	return (res);
}

t_rayres	rayres_new_normal(t_object *obj, t_vec3f p,
		double dist, t_vec3f normal)
{
	t_rayres	res;

	res.obj = obj;
	res.p = p;
	res.dist = dist;
	res.normal = normal;
	return (res);
}
