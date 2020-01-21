/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:32:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/20 16:42:21 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

double			obj_dist(t_object *obj, t_ray ray)
{
	double	res;

	res = INFINITY;
	if (obj->type == SP)
		res = obj_dist_sphere(obj, ray);
	return (res);
}
