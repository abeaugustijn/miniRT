/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:32:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/17 16:32:21 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "obj_dist.h"

t_rayres	obj_dist(t_object *obj, t_ray ray, t_info *info)
{
	if (obj->type == SQ) //TODO
		return (rayres_inf());
	return (g_objdistjump[obj->type](obj, ray, info));
}
