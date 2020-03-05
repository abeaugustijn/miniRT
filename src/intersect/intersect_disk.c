
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:49:01 by abe               #+#    #+#             */
/*   Updated: 2020/02/17 16:34:37 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <math.h>

/*
**	Calculate whether a given ray intersects with a disk.
**
**	@param {t_object *} ds (disk)
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {double}
*/

double	intersect_disk(t_object *ds, t_ray ray, t_info *info)
{
	t_rayres	pl_res;
	t_object	pl;

	ft_bzero(&pl, sizeof(t_object));
	pl.type = PL;
	pl.location = ds->location;
	pl.orientation = ds->orientation;
	pl_res = obj_dist(&pl, ray, info);
	if (pl_res.dist == INFINITY)
		return (INFINITY);
	if (vec_dist(pl_res.p, ds->location) > ds->size / 2)
		return (INFINITY);
	return (pl_res.dist);
}
