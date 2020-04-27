/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 21:30:17 by abe           #+#   #+#                  */
/*   Updated: 2020/02/06 21:31:15 by abe           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	ray_new(t_vec3f origin, t_vec3f direction)
{
	t_ray	res;

	res.direction = direction;
	res.origin = origin;
	return (res);
}
