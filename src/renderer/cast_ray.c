/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:30:00 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/20 16:31:17 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_color	ray_cast(t_info *info, t_ray ray)
{
	t_list		*current;
	t_object	*closest;
	double		min_distance;
	double		dist;

	min_distance = INFINITY;
	closest = NULL;
	current = info->objects;
	while (current)
	{
		dist = obj_dist(current, ray);
		if (dist < min_distance)
		{
			closest = (t_object *)current->content;
			min_distance = dist;
		}
		current = current->next;
	}
}
