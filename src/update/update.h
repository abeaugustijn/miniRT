/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti </var/spool/mail/abe>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/17 10:11:47 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/17 10:46:54 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include <minirt.h>

void	update_dir_vecs(t_dir_vecs *vecs);
void	update_cylinder(t_object *cy, t_info *info);
void	update_disk(t_object *ds, t_info *info);
void	update_plane(t_object *pl, t_info *info);
void	update_square(t_object *sq, t_info *info);

#endif
