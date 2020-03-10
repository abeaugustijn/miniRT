/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:36:33 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/10 14:36:41 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	Select an object in the world by clicking on it. This function will send
**	out a ray to find the closest object to the camera, and set the 'selected'
**	variable in the info struct to point to the object.
**
**	@param {t_vec2i} pixel
**	@param {t_info *} info
*/

void	select_object(t_vec2i pixel, t_info *info)
{
	t_ray		ray;
	t_object	*closest;
	t_object	*current;
	double		dist;
	double		closest_dist;
	size_t		i;

	ray = generate_ray(pixel, info);
	closest = NULL;
	closest_dist = INFINITY;
	i = 0;
	while (!vla_get_addr(info->objects, i, (void **)&current))
	{
		dist = intersect(current, ray, NULL, info);
		if (dist < closest_dist)
		{
			closest_dist = dist;
			closest = current;
			if (closest->has_parent)
				vla_get_addr(info->objects, closest->parent_i,
						(void **)&closest);
		}
		i++;
	}
	if (closest)
		info->selected = closest;
}
