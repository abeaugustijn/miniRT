/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist_disk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:42:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/24 12:34:56 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <math.h>

t_rayres		obj_dist_disk(t_object *ds, t_ray ray, t_info *info)
{
	t_rayres	pl_res;
	t_object	pl;

	ft_bzero(&pl, sizeof(t_object));
	pl.type = PL;
	pl.location = ds->location;
	pl.orientation = ds->orientation;
	pl_res = obj_dist(&pl, ray, info);
	if (pl_res.dist >= INFINITY)
		return (rayres_inf());
	if (vec_dist(pl_res.p, ds->location) > ds->size / 2)
		return (rayres_inf());
	return (rayres_new_dist(ds, pl_res.p, ds->color, vec_dist(ray.origin, pl_res.p)));
}

