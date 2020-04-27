/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_cast.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:30:00 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/08 19:31:04 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray_cast.h"
#include <minirt.h>
#include <math.h>
#include <libft.h>

static void		ray_cast_init_data(struct s_ray_cast_data *data)
{
	data->min_distance = INFINITY;
	data->normal = vec_new(0, 0, 0);
	data->normal_closest = vec_new(0, 0, 0);
	data->closest = NULL;
}

t_color			ray_cast(t_info *info, t_ray ray)
{
	size_t					i;
	struct s_ray_cast_data	data;

	ray_cast_init_data(&data);
	i = 0;
	while (!vla_get_addr(info->objects, i, (void **)&data.current))
	{
		i++;
		if (data.current->type == SQ)
			continue;
		data.dist = intersect(data.current, ray, &data.normal, info);
		if (data.dist >= data.min_distance)
			continue;
		data.normal_closest = vec_is_normal(data.normal) ?
			data.normal : vec_new(0, 0, 0);
		data.normal = vec_new(0, 0, 0);
		data.closest = data.current;
		data.min_distance = data.dist;
	}
	if (!data.closest)
		return (col_new(0, 0, 0));
	return (ray_cast_all_lights(info, rayres_new(data.closest,
					ray_point(ray, data.min_distance), data.min_distance,
					data.normal_closest), ray));
}
