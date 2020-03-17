/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:47:57 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/17 19:03:13 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "rotate.h"

void	rotate_cylinder(t_object *cy, t_move_dir axis, bool increase,
			t_info *info)
{
	rotate_plane(cy, axis, increase, info);
}
