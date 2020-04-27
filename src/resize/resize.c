/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resize.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 12:48:10 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/02/21 14:51:03 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "resize.h"

void	resize(t_object *obj, bool increase, t_info *info)
{
	if (g_resizejump[obj->type])
		g_resizejump[obj->type](obj, increase, info);
}
