/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_disk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 10:18:24 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/17 10:36:31 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "update.h"

void	update_disk(t_object *ds, t_info *info)
{
	(void)info;
	update_dir_vecs(&ds->dir_vecs);
}
