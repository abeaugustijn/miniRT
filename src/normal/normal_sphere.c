/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:39:49 by abe               #+#    #+#             */
/*   Updated: 2020/02/17 13:58:43 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Gets the normal vector of a sphere, on a certain point where the ray hit
**	the sphere.
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f} normal
*/

t_vec3f	normal_sphere(t_rayres rayres, t_info *info)
{
	(void)info;
	return (vec_from_to(rayres.obj->location, rayres.p));
}
