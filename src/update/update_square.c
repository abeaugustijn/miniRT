/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 10:32:40 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/17 10:33:43 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include "update.h"

void	update_square(t_object *sq, t_info *info)
{
	children_square_update(sq, info);
}
