/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:53:08 by abe               #+#    #+#             */
/*   Updated: 2020/02/04 14:49:54 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Normalize a vector.
**
**	@param {t_vec3f} vec
**
**	@return {t_vec3f}
*/

t_vec3f	vec3f_normalize(t_vec3f vec)
{
	double	len;

	len = vec_len(vec);
	return (vec_new(vec.x / len, vec.y / len, vec.z / len));
}
