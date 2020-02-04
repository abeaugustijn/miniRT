/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normalized.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:26:02 by abe               #+#    #+#             */
/*   Updated: 2020/02/04 15:32:09 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Function to check whether a vector is normalized.
**
**	@param {t_vec3f} vec
**
**	@return {bool}
*/

bool		check_normalized(t_vec3f vec)
{
	return (float_compare(vec_len(vec), 1));
}
