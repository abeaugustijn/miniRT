/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_square.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 15:46:01 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/10 14:35:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

/*
**	Calculate whether a given ray intersects with a square. This is always
**	false because the ray will never intersect the square itself, but only
**	it's children.
**
**	@param {t_object *} sq (square)
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {double}
*/

double	intersect_square(t_object *sp, t_ray ray, t_vec3f *normal, t_info *info)
{
	(void)sp;
	(void)ray;
	(void)normal;
	(void)info;
	return (INFINITY);
}
