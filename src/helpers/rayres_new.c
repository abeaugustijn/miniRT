/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rayres_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 13:38:55 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/10 14:30:05 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_rayres	rayres_new(t_object *obj, t_vec3f p, double dist, t_vec3f normal)
{
	t_rayres	res;

	res.obj = obj;
	res.p = p;
	res.dist = dist;
	res.normal = normal;
	return (res);
}
