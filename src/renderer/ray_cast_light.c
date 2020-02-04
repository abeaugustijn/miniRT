/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:24:52 by abe               #+#    #+#             */
/*   Updated: 2020/02/04 16:21:15 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_lightres	ray_cast_light(t_light *light, t_rayres rayres)
{
	t_vec3f		norm;
	t_vec3f 	lightray_dir;
	double		dotp;
	t_lightres	res;

	lightray_dir = vec_from_to(rayres.p, light->location);
	norm = normal(rayres);
	dotp = vec_dotp(lightray_dir, norm);
	if (dotp < 0)
		dotp = 0;
	res.light = light;
	res.factor = dotp;
	res.factor /= 4 * M_PI * pow(vec_dist(light->location, rayres.p), 2);
	return (res);
}
