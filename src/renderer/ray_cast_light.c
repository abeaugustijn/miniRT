/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:24:52 by abe               #+#    #+#             */
/*   Updated: 2020/02/25 20:18:19 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	This checks whether a certain lightray on a surface is obstructed by
**	an object. In this case there will be a shadow on the surface because none
**	of the light will 'hit' the surface.
**
**	@param {t_info *} info
**	@param {t_object *} curr_obj - the object on which the light shines. This
**		object should not be taken into account when checking for intersection
**		with the lightray.
**	@param {t_ray} ray - the lightray
**
**	@return {bool} - true if obstructed
*/

static bool		light_obstructed(t_info *info, t_object *curr_obj, t_ray ray)
{
	t_list	*objects;

	objects = info->objects;
	while (objects)
	{
		if (objects->content != curr_obj &&
				intersect((t_object *)objects->content, ray, info))
			return (true);
		objects = objects->next;
	}
	return (false);
}

/*
**	This calculates the amount of light a surface will reflect if only a
**	single light was shining on it. It returns the resulting color of the
**	light on the surface.
**
**	@param {t_info *} info
**	@param {t_light *} light
**	@param {t_rayres} rayres
**	@param {t_ray} ray
**
**	@return {t_color}
*/

static t_color	ray_cast_light(t_info *info, t_light *light, t_rayres rayres, t_ray ray)
{
	t_vec3f		norm;
	t_vec3f 	lightray_dir;
	double		factor;

	if (float_compare(info->mapinfo.ambient_ratio, 1))
		return (rayres.obj->color);
	if (light_obstructed(info, rayres.obj,
				ray_new(rayres.p, vec_from_to(rayres.p, light->location))))
		return (col_new(0, 0, 0));
	lightray_dir = vec_from_to(rayres.p, light->location);
	norm = normal(rayres, info);
	fix_normal(rayres.obj->type, ray, &norm);
	factor = vec_dotp(lightray_dir, norm);
	if (factor < 0)
		return (col_new(0, 0, 0));
	factor *= light->brightness;
	factor /= 4 * M_PI * pow(vec_dist(light->location, rayres.p), 2);
	return (col_multiply(col_mix_light(light->color, rayres.obj->color), fmin(factor, 1)));
}

/*
**	Generate the color of a surface according to the lights which shine onto
**	it. This will take into account ambient lighting, colored lights and
**	shadows.
**
**	@param {t_info *} info
**	@param {t_rayres} rayres - the info about the surface and the ray
**	@param {t_ray} ray
**
**	@return {t_color} - the resulting color of the surface
*/

t_color				ray_cast_all_lights(t_info *info, t_rayres rayres, t_ray ray)
{
	t_color		res;
	t_list		*lights;

	res = col_multiply(info->mapinfo.ambient_color, info->mapinfo.ambient_ratio);
	res = col_mix_light(rayres.obj->color, res);
	lights = info->lights;
	while (lights)
	{
		res = col_add_light(res, ray_cast_light(info, (t_light *)lights->content, rayres, ray));
		lights = lights->next;
	}
	return (res);
}
