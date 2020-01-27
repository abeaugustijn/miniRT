/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:30:00 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/27 15:05:21 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
#include <libft.h>

static	t_rayres	ray_cast_object(t_info *info, t_ray ray)
{
	t_list		*current;
	t_object	*closest;
	double		min_distance;
	t_rayres	rayres;
	t_rayres	rayres_closest;

	min_distance = INFINITY;
	closest = NULL;
	current = info->objects;
	while (current)
	{
		rayres = obj_dist((t_object *)current->content, ray);
		if (rayres.dist < min_distance)
		{
			closest = (t_object *)current->content;
			min_distance = rayres.dist;
			rayres_closest = rayres;
		}
		current = current->next;
	}
	if (!closest)
		return (rayres_inf());
	return (rayres_closest);
}

t_color	ray_cast(t_info *info, t_ray ray)
{
	t_rayres	obj;
	t_color		res;

	obj = ray_cast_object(info, ray);
	if (obj.dist == INFINITY)
		return (col_new(0, 0, 0));
	res = col_mix_ambient(obj.color, info->mapinfo.ambient_color);
	res = col_multiply(res, info->mapinfo.ambient_ratio);
	return (res);
}
