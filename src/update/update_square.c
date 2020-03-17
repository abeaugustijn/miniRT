/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 10:32:40 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/17 15:14:17 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "update.h"

void	update_square(t_object *sq, t_info *info)
{
	update_dir_vecs(&sq->dir_vecs);
	children_square_update(sq, info);
}
