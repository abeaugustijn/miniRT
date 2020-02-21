/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:36:33 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/21 12:38:55 by aaugusti         ###   ########.fr       */
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
	t_list		*current;
	t_rayres	rayres;
	double		closest_dist;

	ray = generate_ray(pixel, info);
	closest = NULL;
	closest_dist = INFINITY;
	current = info->objects;
	while (current)
	{
		rayres = obj_dist(current->content, ray, info);
		if (rayres.dist < closest_dist)
		{
			closest_dist = rayres.dist;
			closest = current->content;
			if (closest->parent)
				closest = closest->parent;
		}
		current = current->next;
	}
	if (closest)
		info->selected = closest;
}
