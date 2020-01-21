/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:44:35 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/21 11:45:43 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3f	vec_multiply(t_vec3f vec, double factor)
{
	t_vec3f	res;

	res.x = vec.x * factor;
	res.y = vec.y * factor;
	res.z = vec.z * factor;
	return (res);
}
