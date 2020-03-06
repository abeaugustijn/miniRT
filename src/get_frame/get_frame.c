/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:13:56 by abe               #+#    #+#             */
/*   Updated: 2020/03/06 12:03:12 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#ifdef BONUS
# include <pthread.h>
#endif

#define RES info->mapinfo.res

/*
**	Allocates a buffer a fills it with the pixels of the current frame. Bonus
**	one implements multithreading.
**
**	@param {t_info *} info
**
**	@return {t_color *}
*/

#ifndef BONUS

t_color	*get_frame(t_info * info)
{
	t_color		*res;
	uint32_t	x;
	uint32_t	y;

	res = malloc(sizeof(t_color) * RES.x * RES.y);
	if (!res)
		print_error("Allocation failed in 'get_frame'", info);
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

#else

t_color	*get_frame(t_info *info)
{
	t_color			*buf;
	pthread_t		threads[NCORES];
	uint32_t		i;
	t_thread_info	*tinfo[NCORES];

	buf = malloc(sizeof(t_color) * RES.x * RES.y);
	if (!buf)
		print_error("Allocation failed in 'get_frame'", info);
	i = 0;
	while (i < NCORES)
	{
		tinfo[i] = thread_info_new(info, buf, i);
		if (pthread_create(&threads[i], NULL, renderer_thread, tinfo[i]))
			print_error_free("Failed to spawn thread in 'get_frame'",
					info, buf, free);
		i++;
	}
	i = 0;
	while (i < NCORES)
	{
		if ((pthread_join(threads[i], NULL)))
			print_error_free("pthread_join failed in 'get_frame'",
					info, buf, free);
		i++;
	}
	return (buf);
}

#endif
