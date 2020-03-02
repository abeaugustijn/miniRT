/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:30:00 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/02 19:26:31 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
#include <libft.h>

static t_rayres	ray_cast_object(t_info *info, t_ray ray)
{
	t_object	*current;
	t_object	*closest;
	double		min_distance;
	t_rayres	rayres;
	t_rayres	rayres_closest;
	size_t		i;

	min_distance = INFINITY;
	closest = NULL;
	i = 0;
	while (!vla_get_addr(info->objects, i, (void **)&current))
	{
		if (current->type == SQ)
			continue;
		rayres = obj_dist(current, ray, info);
		if (rayres.dist < min_distance)
		{
			closest = current;
			min_distance = rayres.dist;
			rayres_closest = rayres;
		}
		i++;
	}
	if (!closest)
		return (rayres_inf());
	return (rayres_closest);
}

t_color			ray_cast(t_info *info, t_ray ray)
{
	t_rayres	rayres;

	rayres = ray_cast_object(info, ray);
	if (rayres.dist == INFINITY)
		return (col_new(0, 0, 0));
	return (ray_cast_all_lights(info, rayres, ray));
}
