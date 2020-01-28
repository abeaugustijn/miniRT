/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:24:52 by abe               #+#    #+#             */
/*   Updated: 2020/01/28 22:12:44 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_lightres	ray_cast_light(t_info *info, t_rayres rayres)
{
	t_vec3f		norm;
	t_vec3f 	lighray_dir;
	double		dotp;
	t_lightres	res;

	lighray_dir = vec_sub(((t_light *)info->lights->content)->location, rayres.p);
	lighray_dir = vec3f_normalize(lighray_dir);
	norm = normal(rayres);
	dotp = vec_dotp(lighray_dir, norm);
	if (dotp < 0)
		dotp = 0;
	res.light = info->lights->content;
	res.factor = dotp;
	return (res);
}
