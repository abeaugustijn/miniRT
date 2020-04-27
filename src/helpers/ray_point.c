/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_point.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 16:17:45 by abe           #+#   #+#                  */
/*   Updated: 2020/03/04 16:20:20 by abe           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Get a point on the given ray.
**
**	@param {t_ray} ray
**	@param {double} t
**
**	@return {t_vec3f}
*/

inline t_vec3f	ray_point(t_ray ray, double t)
{
	return (vec_add(ray.origin, vec_multiply(ray.direction, t)));
}
