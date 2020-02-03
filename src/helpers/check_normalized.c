/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normalized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:26:02 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 16:11:41 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	check_one(double val)
{
	return (val >= -1 && val <= 1);
}

/*
**	Function to check whether a vector is normalized.
**
**	@param {t_vec3f} vec
**
**	@return {bool}
*/

bool		check_normalized(t_vec3f vec)
{
	if (vec_len(vec) != 1)
		return (false);
	return (check_one(vec.x) &&
			check_one(vec.y) &&
			check_one(vec.z));
}
