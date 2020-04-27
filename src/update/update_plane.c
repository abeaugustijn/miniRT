/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_plane.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 10:30:14 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 16:51:20 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "update.h"

void	update_plane(t_object *pl, t_info *info)
{
	(void)info;
	update_dir_vecs(&pl->dir_vecs);
}
