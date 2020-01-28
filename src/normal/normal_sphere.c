/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:39:49 by abe               #+#    #+#             */
/*   Updated: 2020/01/28 21:40:47 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3f	normal_sphere(t_rayres rayres)
{
	t_vec3f	res;

	res = vec_sub(rayres.p, rayres.obj->location);
	return (vec3f_normalize(res));
}
