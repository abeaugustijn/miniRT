/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resize_sphere.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 12:52:47 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/02/21 14:03:00 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

void	resize_sphere(t_object *sp, bool increase, t_info *info)
{
	(void)info;
	sp->size *= pow(RESIZE_SPEED, increase ? 1 : -1);
}
