/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:30:00 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/06 21:14:46 by abe              ###   ########.fr       */
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
	t_rayres	rayres;

	rayres = ray_cast_object(info, ray);
	if (rayres.dist == INFINITY)
		return (col_new(0, 0, 0));
	return (ray_cast_all_lights(info, rayres));
}
