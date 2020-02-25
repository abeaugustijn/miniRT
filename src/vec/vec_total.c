/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_total.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:00:41 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/25 17:01:24 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Get the total of all values in a vector.
**
**	@param {t_vec3f} vec
**
**	@return {double}
*/

double			vec_total(t_vec3f vec)
{
	return (vec.x + vec.y + vec.z);
}
