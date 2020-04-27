/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal_cylinder.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 17:33:17 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/10 15:23:16 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Get the normal vector for a plane.
**
**	@param {t_rayres} rayres
**
**	@return {t_vec3f}
*/

t_vec3f	normal_cylinder(t_rayres rayres, t_ray ray, t_info *info)
{
	(void)rayres;
	(void)ray;
	(void)info;
	return (vec_new(1, 0, 0));
}
