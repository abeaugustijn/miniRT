/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:32:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/07 17:30:22 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres		(*g_jumpobj[])(t_object *, t_ray) = {
	&obj_dist_sphere,
	&obj_dist_plane,
	NULL,	//TODO SQ
	&obj_dist_cylinder,
	NULL	//TODO TR
};

t_rayres	obj_dist(t_object *obj, t_ray ray)
{
	return (g_jumpobj[obj->type](obj, ray));
}
