/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multiply_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:58:21 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/25 17:00:07 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Multuiply two vectors with each other.
**
**	@param {t_vec3f} a
**	@param {t_vec3f} b
**
**	@return {t_vec3f}
*/

t_vec3f	vec_multiply_vec(t_vec3f a, t_vec3f b)
{
	return (vec_new(a.x * b.x, a.y * b.y, a.z * b.z));
}
