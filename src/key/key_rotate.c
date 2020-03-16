/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:40:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/16 22:40:37 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <key_codes.h>
#include <math.h>

void	key_rotate(int keycode, t_info *info)
{
	if (info->selected)
		rotate_obj(keycode, info);
	else
		rotate_cam(keycode, info);
}
