/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_disk.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 10:18:24 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 16:51:04 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "update.h"

void	update_disk(t_object *ds, t_info *info)
{
	(void)info;
	update_dir_vecs(&ds->dir_vecs);
}
