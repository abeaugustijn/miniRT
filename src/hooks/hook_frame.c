/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 14:17:21 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 12:25:13 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <mlx.h>
#include <stdlib.h>

static void	pixel_put(t_mlximg img, uint16_t x, uint16_t y, t_color color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bpp / 8));
	*(unsigned int *)dst = to_color(color);
}

/*
**	The hook function which executes on every frame. This calls 'get_pixel' for
**	every pixel on the screen, except for when the 'rendered' flag in the info
**	struct is set to true.
**
**	@param {t_info *} info
**
**	@return {int} (not used)
*/

int			hook_frame(t_info *info)
{
	t_color		*frame;
	uint16_t	i;
	uint16_t	j;

	if (info->mapinfo.rendered)
		return (0);
	info->mapinfo.rendered = true;
	frame = get_frame(info);
	i = 0;
	while (i < info->mapinfo.res.x)
	{
		j = 0;
		while (j < info->mapinfo.res.y)
		{
			pixel_put(
					info->mlx_info.img, i, j,
					frame[i * info->mapinfo.res.y + j]);
			j++;
		}
		i++;
	}
	free(frame);
	mlx_put_image_to_window(info->mlx_info.mlx, info->mlx_info.mlx_win,
			info->mlx_info.img.ptr, 0, 0);
	return (0);
}
