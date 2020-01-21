/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:17:30 by abe               #+#    #+#             */
/*   Updated: 2020/01/21 21:41:18 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>

t_color	*get_frame(t_info *info)
{
	t_color	*res;
	t_vec2i	pixel;
	uint16_t	i;
	uint16_t	j;

	res = (t_color *)malloc(info->mapinfo.res.x * info->mapinfo.res.y *
			sizeof(t_color));
	if (!res)
		print_error("Allocation failed in 'get_frame'\n");
	i = 0;
	while (i < info->mapinfo.res.x)
	{
		j = 0;
		pixel.x = i;
		while (j < info->mapinfo.res.y)
		{
			pixel.y = j;
			res[info->mapinfo.res.y * i + j] = get_pixel(pixel, info);
			j++;
		}
		i++;
	}
	return (res);
}
