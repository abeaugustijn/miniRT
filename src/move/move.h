/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 13:31:09 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 17:13:21 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include <minirt.h>

void	move_sphere(t_object *sp, t_move_dir move_dir, t_info *info);
void	move_plane(t_object *pl, t_move_dir move_dir, t_info *info);
void	move_square(t_object *sq, t_move_dir move_dir, t_info *info);
void	move_cylinder(t_object *cy, t_move_dir move_dir, t_info *info);
void	move_triangle(t_object *tr, t_move_dir move_dir, t_info *info);
void	move_disk(t_object *ds, t_move_dir move_dir, t_info *info);

void	(*g_movejmp[])(t_object *, t_move_dir, t_info *) = {
	[SP] = &move_sphere,
	[PL] = &move_plane,
	[SQ] = &move_square,
	[CY] = &move_cylinder,
	[TR] = &move_triangle,
	[DS] = &move_disk,
};

#endif
