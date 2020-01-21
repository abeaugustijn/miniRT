/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:42:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/20 16:47:03 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
 
static bool	does_intersect(t_object *sp, t_ray ray)
{
	double	determinant;

	return (determinant >= 0);
}

double	obj_dist_sphere(t_object *sp, t_ray ray)
{
	double	dist_to_center;

	if (!does_intersect(sp, ray))
		return (INFINITY);
	dist_to_center = vec
}

