/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:17:53 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/03 13:18:53 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

bool	vec_compare(t_vec3f a, t_vec3f b)
{
	return (float_compare(a.x, b.x) &&
			float_compare(a.y, b.y) &&
			float_compare(a.z, b.z));
}
