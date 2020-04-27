/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti </var/spool/mail/abe>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/16 22:16:24 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 17:14:01 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

# include <minirt.h>

void	rotate_get_dir(int keycode, t_move_dir *axis, bool *increase);
void	rotate_plane(t_object *pl, t_move_dir axis, bool increase,
			t_info *info);
void	rotate_square(t_object *sq, t_move_dir axis, bool increase,
			t_info *info);

#endif
