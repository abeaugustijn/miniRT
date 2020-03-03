/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:52:00 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/03 16:44:40 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3f			vec_new(double x, double y, double z)
{
	t_vec3f	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.normalize = &vec_normalize;
	return (res);
}
