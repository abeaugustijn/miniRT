/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_cast_light.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 21:24:52 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 16:44:25 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

/*
**	This checks whether a certain lightray on a surface is obstructed by
**	an object. In this case there will be a shadow on the surface because none
**	of the light will 'hit' the surface.
**
**	@param {t_info *} info
**	@param {t_light *} light
**	@param {t_object *} reflect_obj - the object on which the light shines. This
**		object should not be taken into account when checking for intersection
**		with the lightray.
**	@param {t_ray} ray - the lightray
**
**	@return {bool} - true if obstructed
*/

static bool		light_obstructed(t_info *info, t_light *light,
					t_object *reflect_obj, t_ray ray)
{
	t_object	*current;
	double		dist;
	size_t		i;

	i = 0;
	dist = vec_dist(ray.origin, light->location);
	while (!vla_get_addr(info->objects, i, (void **)&current))
	{
		i++;
		if (current == reflect_obj)
			continue;
		if (intersect(current, ray, NULL, info) < dist - EPSILON)
			return (true);
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

static t_color	ray_cast_light(t_info *info, t_light *light, t_rayres rayres,
					t_ray ray)
{
	t_vec3f		norm;
	t_vec3f		lightray_dir;
	double		factor;

	if (float_compare(info->mapinfo.ambient_ratio, 1))
		return (rayres.obj->color);
	if (light_obstructed(info, light, rayres.obj,
				ray_new(rayres.p, vec_from_to(rayres.p, light->location))))
		return (col_new(0, 0, 0));
	lightray_dir = vec_from_to(rayres.p, light->location);
	norm = vec_is_normal(rayres.normal) ?
		fix_normal(ray.direction, rayres.normal) :
		normal(rayres, ray, info);
	factor = vec_dotp(lightray_dir, norm);
	if (factor < 0)
		return (col_new(0, 0, 0));
	factor *= light->brightness;
	factor /= 4 * M_PI * pow(vec_dist(light->location, rayres.p), 2);
	return (col_multiply(col_mix_light(light->color, rayres.obj->color),
				fmin(factor, 1)));
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

t_color			ray_cast_all_lights(t_info *info, t_rayres rayres,
		t_ray ray)
{
	t_color		res;
	t_light		*current;
	size_t		i;

	res = col_multiply(info->mapinfo.ambient_color,
			info->mapinfo.ambient_ratio);
	res = col_mix_light(rayres.obj->color, res);
	i = 0;
	while (!vla_get_addr(info->lights, i, (void **)&current))
	{
		res = col_add_light(res, ray_cast_light(info, current, rayres, ray));
		i++;
	}
	return (res);
}
