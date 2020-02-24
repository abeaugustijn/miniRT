/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:13:56 by abe               #+#    #+#             */
/*   Updated: 2020/02/24 22:17:26 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>

#define RES info->mapinfo.res

/*
**	Allocates a buffer a fills it with the pixels of the current frame.
**
**	@param {t_info *} info
**
**	@return {t_color *}
*/

t_color	*get_frame(t_info * info)
{
	t_color		*res;
	uint32_t	x;
	uint32_t	y;

	res = malloc(sizeof(t_color) * RES.x * RES.y);
	if (!res)
		print_error("Allocation failed in 'get_frame'\n", info);
	x = 0;
	while (x < RES.x)
	{
		y = 0;
		while (y < RES.y)
		{
			res[x * RES.y + y] = get_pixel((t_vec2i){x, y}, info);
			y++;
		}
		x++;
	}
	return (res);
}
