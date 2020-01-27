/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayres_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:38:55 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/27 18:59:16 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_rayres	rayres_new(t_vec3f p, t_color color)
{
	t_rayres	res;

	res.p = p;
	res.color = color;
	res.dist = 0;
	return (res);
}

t_rayres	rayres_new_dist(t_vec3f p, t_color color, double dist)
{
	t_rayres	res;

	res.p = p;
	res.color = color;
	res.dist = dist;
	return (res);
}
