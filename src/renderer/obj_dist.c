/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:32:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/24 09:54:30 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

double			obj_dist(t_object *obj, t_ray ray, t_color *color, t_info *info)
{
	double	res;

	res = INFINITY;
	if (obj->type == SP)
		res = obj_dist_sphere(obj, ray, color, info);
	return (res);
}
