/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer_thread.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 12:49:42 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 12:24:02 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <pthread.h>
#include <stdlib.h>

/*
**	The thread function for rendering pixels. This function gets a t_thread_info
**	struct which contains a start value for the pixel where it should start
**	rendering. This value is alway increased by NCORES so we end up with all
**	pixels.
**
**	@param {void *} param - in reality this is a {t_thread_info *}
**
**	@return {void *} - not used
*/

void	*renderer_thread(void *param)
{
	t_thread_info	*tinfo;
	uint32_t		i;

	tinfo = param;
	i = tinfo->start;
	while (i < tinfo->info->mapinfo.tot_pixels)
	{
		tinfo->buf[i] =
			get_pixel((t_vec2i){i / tinfo->info->mapinfo.res.y,
					i % tinfo->info->mapinfo.res.y}, tinfo->info);
		i += NCORES;
	}
	free(param);
	pthread_exit(NULL);
}
