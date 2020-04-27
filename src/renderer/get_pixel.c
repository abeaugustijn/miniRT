/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pixel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 15:36:58 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 14:25:32 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

/*
**	Get the color of a certain pixel on the screen. This function generates
**	a ray for the given pixel and casts it by calling 'ray_cast' with the
**	generated ray.
**
**	@param {t_vec2i} pixel - should be valid values, otherwise undefined be-
**		haviour will occur.
**	@param {t_info *} info
**
**	@return {t_color}
*/

t_color			get_pixel(t_vec2i pixel, t_info *info)
{
	return (ray_cast(info, generate_ray(pixel, info)));
}
