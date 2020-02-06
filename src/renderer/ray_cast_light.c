/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:24:52 by abe               #+#    #+#             */
/*   Updated: 2020/02/06 20:47:21 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

static t_color	light_add(t_color col, t_color to_add)
{
	return (col_new(max(col.r, to_add.r),
				max(col.g, to_add.g),
				max(col.b, to_add.b)));
}

static t_color	ray_cast_light(t_light *light, t_rayres rayres)
{
	t_vec3f		norm;
	t_vec3f 	lightray_dir;
	double		factor;

	lightray_dir = vec_from_to(rayres.p, light->location);
	norm = normal(rayres);
	factor = vec_dotp(lightray_dir, norm);
	if (factor < 0)
		return (col_new(0, 0, 0));
	factor *= light->brightness;
	factor /= 4 * M_PI * pow(vec_dist(light->location, rayres.p), 2);
	return (col_multiply(col_mix_light(light->color, rayres.obj->color), factor));
}

t_color				ray_cast_all_lights(t_info *info, t_rayres rayres)
{
	t_color		res;
	t_list		*lights;

	res = col_multiply(info->mapinfo.ambient_color, info->mapinfo.ambient_ratio);
	lights = info->lights;
	while (lights)
	{
		res = light_add(res, ray_cast_light((t_light *)lights->content, rayres));
		lights = lights->next;
	}
	return (res);
}
