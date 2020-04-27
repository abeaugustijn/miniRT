/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_disk.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:49:01 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 12:29:05 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
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

double	intersect_disk(t_object *ds, t_ray ray, t_vec3f *normal, t_info *info)
{
	double		t;
	t_vec3f		p;
	t_object	pl;

	(void)normal;
	ft_bzero(&pl, sizeof(t_object));
	pl.type = PL;
	pl.location = ds->location;
	pl.dir_vecs.forward = ds->dir_vecs.forward;
	t = intersect(&pl, ray, NULL, info);
	if (t == INFINITY)
		return (INFINITY);
	p = ray_point(ray, t);
	if (vec_dist(p, ds->location) > ds->size / 2)
		return (INFINITY);
	return (t);
}
