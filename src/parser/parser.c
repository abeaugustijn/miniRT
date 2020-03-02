/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:21:16 by abe               #+#    #+#             */
/*   Updated: 2020/03/02 22:21:50 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <fcntl.h>
#include <unistd.h>
#include <get_next_line.h>
#include <stdlib.h>
#include <libft.h>
#include "parse_functions.h"

/*
**	Convert all VLAs to arrays.
**
**	@param {t_info *} info
*/

static void	convert_vlas(t_info *info)
{
	if (vla_shrink(&info->cameras) ||
		vla_shrink(&info->lights) ||
		vla_shrink(&info->objects))
		print_error("Allocation failed in 'convert_vlas'", info);
}

/*
**	Initialize all the VLAs for the parsing.
**
**	@param {t_info *} info
*/

static void	init_vlas(t_info *info)
{
	if (vla_init(sizeof(t_camera), 20, &info->cameras) ||
			vla_init(sizeof(t_light), 20, &info->lights) ||
			vla_init(sizeof(t_object), 20,  &info->objects))
		print_error("Allocation failed in 'init_vlas'", info);
}

/*
**	Function to check whether the filename has the '*.rt' format.
**
**	@param {char *} filename
**
**	@return {bool} - returns 1 if the filename is invalid
*/

static bool	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	return (filename[i - 3] != '.' ||
			filename[i - 2] != 'r' ||
			filename[i - 1] != 't');
}

/*
**	Parse a single line of the .rt file. Uses a jumptable called 'g_parsejump'
**	to decide which function to call for every specifier.
**
**	@param {char *} line
**	@param {t_info *} info
*/

static void	parse_line(char *line, t_info *info)
{
	char	**words;
	uint8_t	i;

	words = ft_split(line, ' ');
	if (words == NULL)
		print_error_free_words("Memory allocation failed in parse_line\n",
				info, words);
	if (!words[0])
	{
		free_words(words);
		return ;
	}
	i = 0;
	while (g_parsejump[i].identifier)
	{
		if (!ft_strcmp(words[0], g_parsejump[i].identifier))
		{
			g_parsejump[i].func(words, info);
			free_words(words);
			return ;
		}
		i++;
	}
	print_error_free_words("Invalid line\n", info, words);
}

/*
**	Parse a *.rt file for use as input for miniRT.
**
**	@param {char *} filename
**	@param {t_info *}
*/

void		parse_input(char *filename, t_info *info)
{
	int		fd;
	char	*line;

	if (check_filename(filename))
		print_error("Invalid file extension\n", info);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Opening file went wrong\n", info);
	init_vlas(info);
	while (get_next_line(fd, &line) == 1)
	{
		if (*line != '#')
			parse_line(line, info);
		free(line);
	}
	free(line);
	convert_vlas(info);
	if (!info->mapinfo.did_ambient || !info->mapinfo.did_resolution)
		print_error("Invalid file. R and A have to be present\n", info);
	if (info->cameras.size == 0)
		print_error("At least one camera should be defined\n", info);
	if (info->lights.size == 0)
		print_error("At least one light should be defined\n", info);
	close(fd);
}
