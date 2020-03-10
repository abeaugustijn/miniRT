/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayres_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:38:55 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/10 12:08:36 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_rayres	rayres_new(t_object *obj, t_vec3f p)
{
	t_rayres	res;

	res.obj = obj;
	res.p = p;
	res.dist = 0;
	return (res);
}

t_rayres	rayres_new_dist(t_object *obj, t_vec3f p, double dist)
{
	t_rayres	res;

	res.obj = obj;
	res.p = p;
	res.dist = dist;
	return (res);
}
