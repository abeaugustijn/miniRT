/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:33:01 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 16:49:12 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <fcntl.h>
#include <unistd.h>
#include <libft.h>
#include <stdlib.h>

/*
**	Calculate the total size of the file.
**	Comes down to sizeof(header) + sizeof(bmpinfo_header) + 3 * x * y
**
**	@param {t_info *} info
**
**	@return {size_t}
*/

static size_t	bmp_fsize(t_info *info)
{
	size_t	res;

	res = 14;
	res += 40;
	res += 3 * info->mapinfo.tot_pixels;
	return (res);
}

/*
**	Writes the header for the bmp file to the buffer.
**
**	@param {char *} buf
**	@param {size_t} fsize
*/

static void		bmp_wr_header(char *buf, size_t fsize)
{
	*((uint16_t *)&buf[0x00]) = (uint16_t)0x4d42;
	*((uint32_t *)&buf[0x02]) = (uint32_t)fsize;
	*((uint32_t *)&buf[0x0A]) = (uint32_t)0x0E + 40;
}

/*
**	Writes the info header for the bmp file to the buffer.
**
**	@param {char *} buf
**	@param {t_info *} info
*/

static void		bmp_wr_info_header(char *buf, t_info *info)
{
	*((uint32_t *)&buf[0x0E]) = (uint32_t)40;
	*((uint32_t *)&buf[0x12]) = (uint32_t)info->mapinfo.res.x;
	*((uint32_t *)&buf[0x16]) = (uint32_t)info->mapinfo.res.y;
	*((uint16_t *)&buf[0x1A]) = (uint16_t)1;
	*((uint16_t *)&buf[0x1C]) = (uint16_t)24;
}

/*
**	Writes the pixels to the buffer.
**
**	@param {char *} buf
**	@param {t_info *} info
*/

static void		bmp_wr_pixels(char *buf, t_info *info)
{
	uint32_t	index;
	uint32_t	x;
	uint32_t	y;
	t_color		*frame;
	t_color		col;

	index = 0x0E + 40;
	frame = get_frame(info);
	y = info->mapinfo.res.y - 1;
	while (y > 0)
	{
		x = 0;
		while (x < info->mapinfo.res.x)
		{
			col = frame[x * info->mapinfo.res.y + y];
			buf[index + 0] = col.b;
			buf[index + 1] = col.g;
			buf[index + 2] = col.r;
			index += 3;
			x++;
		}
		y--;
	}
	free(frame);
}

/*
**	Save the scene in a 'scene.bmp' file. The scene will be rendered according
**	to the first camera in the scene file.
**
**	@param {t_info *} info
*/

void			save_bmp(t_info *info)
{
	char	*buf;
	int		fd;
	size_t	fsize;

	fd = open(FILE_NAME, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		print_error("Failed to open the bmp file\n", info);
	fsize = bmp_fsize(info);
	buf = malloc(fsize);
	if (!buf)
		print_error("Allocation failed in 'save_bmp'\n", info);
	ft_bzero(buf, fsize);
	bmp_wr_header(buf, fsize);
	bmp_wr_info_header(buf, info);
	bmp_wr_pixels(buf, info);
	if (write(fd, buf, fsize) < 0)
		print_error("Writing to file failed in 'save_bmp'\n", info);
	if (close(fd) < 0)
		print_error("Closing file failed in 'save_bmp'\n", info);
	free(buf);
}
