/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normalized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:26:02 by abe               #+#    #+#             */
/*   Updated: 2020/02/01 15:11:02 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Function to check whether a vector is normalized.
*/

static bool	check_one(float val)
{
	return (val >= -1 && val <= 1);
}

bool		check_normalized(t_vec3f vec)
{
	if (vec_len(vec) != 1)
		return (false);
	return (check_one(vec.x) &&
			check_one(vec.y) &&
			check_one(vec.z));
}
