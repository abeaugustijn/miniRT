/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:40:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/06 12:30:24 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <key_codes.h>
#include <math.h>

void	key_rotate(int keycode, t_info *info)
{
	(info->selected ? rotate_obj : rotate_cam)(keycode, info);
}
