/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_from_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:22:57 by abe               #+#    #+#             */
/*   Updated: 2020/01/31 12:25:06 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Generates a normalized vector which indicates a direction from point to
**	point in 3d space.
**
**	@param {t_vec3f} from
**	@param {t_vec3f} to
**
**	@param {t_vec3f} (normalized)
*/

t_vec3f	vec_from_to(t_vec3f from, t_vec3f to)
{
	return (vec3f_normalize(vec_sub(to, from)));
}
