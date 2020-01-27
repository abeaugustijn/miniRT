/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:30:00 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/27 14:14:28 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
#include <libft.h>

t_color	ray_cast(t_info *info, t_ray ray)
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
		return (col_new(0, 0, 0));
	return (rayres_closest.color);
}
