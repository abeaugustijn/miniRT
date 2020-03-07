/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:30:00 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/07 15:57:45 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
#include <libft.h>

	#include <assert.h>

static t_rayres	ray_cast_object(t_info *info, t_ray ray)
{
	t_object	*current;
	t_object	*closest;
	double		min_distance;
	double		dist;
	size_t		i;

	min_distance = INFINITY;
	closest = NULL;
	i = 0;
	while (!vla_get_addr(info->objects, i, (void **)&current))
	{
		i++;
		if (current->type == SQ)
			continue;
		dist = intersect(current, ray, info);
		if (dist < min_distance)
		{
			closest = current;
			min_distance = dist;
		}
	}
	if (!closest)
		return (rayres_inf());
	assert(dist >= 0);
	return (rayres_new_dist(closest, ray_point(ray, min_distance), min_distance));
}

t_color			ray_cast(t_info *info, t_ray ray)
{
	t_rayres	rayres;

	rayres = ray_cast_object(info, ray);
	if (rayres.dist == INFINITY)
		return (col_new(0, 0, 0));
	return (ray_cast_all_lights(info, rayres, ray));
}
