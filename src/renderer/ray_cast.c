/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:30:00 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/06 16:42:16 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>
#include <libft.h>

static t_rayres	ray_cast_object(t_info *info, t_ray ray)
{
	t_object	*current;
	t_object	*closest;
	double		min_distance;
	double		dist;
	size_t		i;
	t_vec3f		normal;
	t_vec3f		normal_closest;

	min_distance = INFINITY;
	normal = vec_new(0, 0, 0);
	normal_closest = vec_new(0, 0, 0);
	closest = NULL;
	i = 0;
	while (!vla_get_addr(info->objects, i, (void **)&current))
	{
		i++;
		if (current->type == SQ)
			continue;
		dist = intersect(current, ray, &normal, info);
		if (dist >= min_distance)
			continue;
		normal_closest = vec_is_normal(normal) ? normal : vec_new(0, 0, 0);
		closest = current;
		min_distance = dist;
	}
	if (!closest)
		return (rayres_inf());
	return (rayres_new(closest, ray_point(ray, min_distance),
				min_distance, normal_closest));
}

t_color			ray_cast(t_info *info, t_ray ray)
{
	t_rayres	rayres;

	rayres = ray_cast_object(info, ray);
	if (rayres.dist == INFINITY)
		return (col_new(0, 0, 0));
	return (ray_cast_all_lights(info, rayres, ray));
}
