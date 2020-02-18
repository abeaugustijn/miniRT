/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cam_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:01:15 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/18 15:32:04 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
#include <key_codes.h>

void			key_cam_cycle(int keycode, t_info *info)
{
	t_list		*cam_container;
	t_camera	*old_cam;

	cam_container = lst_find_parent(info->current_cam, info->cameras);
	if (!cam_container)
		print_error(
	"Crashed in 'key_cam_cycle'. Abe made a big mistake. He is sorry.\n", info);
	old_cam = info->current_cam;
	if (keycode == KEY_D)
	{
		if (cam_container->next)
			info->current_cam = cam_container->next->content;
		else
			info->current_cam = info->cameras->content;
	}
	else if (keycode == KEY_A)
	{
		if (cam_container->prev)
			info->current_cam = cam_container->prev->content;
		else
			info->current_cam = lst_last(info->cameras)->content;
	}
	if (info->current_cam != old_cam)
		info->mapinfo.rendered = false;
}
