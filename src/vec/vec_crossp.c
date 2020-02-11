/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_crossp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:53:17 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/11 10:58:12 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Take the cross product of two vectors.
**
**	@param {t_vec3f} a
**	@param {t_vec3f} b
**
**	@return {t_vec3f}
*/

t_vec3f	vec_crossp(t_vec3f a, t_vec3f b)
{
	return (vec_new(a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x));
}
