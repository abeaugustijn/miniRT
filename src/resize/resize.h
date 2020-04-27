/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resize.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 12:51:04 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 17:13:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESIZE_H
# define RESIZE_H

# include <minirt.h>

void	resize_sphere(t_object *sp, bool increase, t_info *info);
void	resize_square(t_object *sq, bool increase, t_info *info);
void	resize_cylinder(t_object *cy, bool increase, t_info *info);

void	(*g_resizejump[])(t_object *, bool, t_info *) = {
	[SP] = &resize_sphere,
	[PL] = NULL,
	[SQ] = &resize_square,
	[CY] = &resize_cylinder,
	[TR] = NULL,
	[DS] = NULL,
};

#endif
