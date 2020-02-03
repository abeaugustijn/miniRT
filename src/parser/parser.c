/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:21:16 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 14:52:48 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <fcntl.h>
#include <unistd.h>
#include <get_next_line.h>
#include <stdlib.h>
#include <liblist.h>
#include <libft.h>
#include "parse_functions.h"

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
**		to decide which function to call for every specifier.
**
**	@param {char *} line
**	@param {t_mapinfo *} mapinfo - to store the data
**	@param {t_list *} objects - a pointer to a linked list to store the objects in
*/

static void	parse_line(char *line, t_info *info)
{
	char	**words __attribute__ ((__cleanup__(free_string_arr)));
	uint8_t	i;

	words = ft_split(line, ' ');
	if (words == NULL)
		print_error("Memory allocation failed in parse_line\n", info);
	if (!words[0])
		return ;
	i = 0;
	while (g_parsejump[i].identifier)
	{
		if (!ft_strcmp(words[0], g_parsejump[i].identifier))
		{
			g_parsejump[i].func(words, info);
			return ;
		}
		i++;
	}
	print_error("Invalid line\n", info);
}

/*
**	Parse a *.rt file for use as input for miniRT.
**
**	@param {char *} filename
**	@param {t_mapinfo *} - a pointer to the mapinfo struct to store the parsed
**		data in.
**	@param {t_list *} objects - a pointer to a linked list to store the objects in
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
	while (get_next_line(fd, &line) == 1)
	{
		if (*line != '#')
			parse_line(line, info);
		free(line);
	}
	if (!info->mapinfo.did_ambient || !info->mapinfo.did_resolution)
		print_error("Invalid file. R and A have to be present\n", info);
	if (!info->cameras || !info->lights)
		print_error("At least one camera and light should be defined\n", info);
	close(fd);
}
