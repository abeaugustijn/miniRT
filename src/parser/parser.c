/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 20:21:16 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 14:20:34 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>
#include <get_next_line.h>
#include <libft.h>
#include <minirt.h>
#include <stdlib.h>
#include <unistd.h>

/*
**	All of the parse functions with their identifiers.
*/

#ifndef BONUS

t_parsefunc		g_parsejump[] = {
	{ "R", parse_resolution },
	{ "A", parse_ambient },
	{ "c", parse_camera },
	{ "l", parse_light },
	{ "sp", parse_sphere },
	{ "pl", parse_plane },
	{ "sq", parse_square },
	{ "cy", parse_cylinder },
	{ "tr", parse_triangle },
	{ NULL, NULL },
};

#else

t_parsefunc		g_parsejump[] = {
	{ "R", parse_resolution },
	{ "A", parse_ambient },
	{ "c", parse_camera },
	{ "l", parse_light },
	{ "sp", parse_sphere },
	{ "pl", parse_plane },
	{ "sq", parse_square },
	{ "cy", parse_cylinder },
	{ "tr", parse_triangle },
	{ "ds", parse_disk },
	{ NULL, NULL },
};

#endif

/*
**	Replace all the tabs in the line with spaces.
**
**	@param {char *} line
*/

static void	replace_tabs(char *line)
{
	while (*line)
	{
		if (*line == '\t')
			*line = ' ';
		line++;
	}
}

/*
**	Check whether certain required things are parsed correctly.
**
**	@param {t_info *} info
*/

static void	parse_input_check(t_info *info)
{
	if (!info->mapinfo.did_ambient || !info->mapinfo.did_resolution)
		print_error("Invalid file. R and A have to be present", info);
	if (info->cameras.size == 0)
		print_error("At least one camera should be defined", info);
	if (info->lights.size == 0)
		print_error("At least one light should be defined", info);
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

	replace_tabs(line);
	words = ft_split(line, ' ');
	if (words == NULL)
		print_error_free_words("Memory allocation failed in parse_line",
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
	print_error_free_words("Invalid line", info, words);
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

	if (parse_check_filename(filename))
		print_error("Invalid file extension\n", info);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Opening file went wrong\n", info);
	parse_init_vlas(info);
	while (get_next_line(fd, &line) == 1)
	{
		info->current_line = line;
		if (*line != '#')
			parse_line(line, info);
		free(line);
		info->current_line = NULL;
	}
	free(line);
	info->current_line = NULL;
	parse_convert_vlas(info);
	parse_input_check(info);
	close(fd);
}
