/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 10:30:14 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/17 10:36:17 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "update.h"

void	update_plane(t_object *pl, t_info *info)
{
	(void)info;
	update_dir_vecs(&pl->dir_vecs);
}
