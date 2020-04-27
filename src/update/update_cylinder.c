/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_cylinder.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 10:38:52 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/17 10:38:53 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "update.h"

void	update_cylinder(t_object *cy, t_info *info)
{
	update_dir_vecs(&cy->dir_vecs);
	children_cylinder_update(cy, info);
}
