/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:21:16 by abe               #+#    #+#             */
/*   Updated: 2020/01/27 18:38:32 by abe              ###   ########.fr       */
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
**	Parse a single line of the .rt file.
**
**	@param {char *} line
**	@param {t_mapinfo *} mapinfo - to store the data
**	@param {t_list *} objects - a pointer to a linked list to store the objects in
*/

static void	parse_line(char *line, t_info *info)
{
	char	**words;

	words = ft_split(line, ' ');
	if (words == NULL)
		print_error("Memory allocation failed\n");
	if (!words[0])
		return ;
	if (ft_strcmp(words[0], "R") == 0)
		parse_resolution(words, info);
	else if (ft_strcmp(words[0], "A") == 0)
		parse_ambient(words, info);
	else if (ft_strcmp(words[0], "c") == 0)
		parse_camera(words, info);
	else if (ft_strcmp(words[0], "l") == 0)
		parse_light(words, info);
	else if (ft_strcmp(words[0], "sp") == 0)
		parse_sphere(words, info);
	else if (ft_strcmp(words[0], "pl") == 0)
		parse_plane(words, info);
	else if (ft_strcmp(words[0], "sq") == 0)
		parse_square(words, info);
	else if (ft_strcmp(words[0], "cy") == 0)
		parse_cylinder(words, info);
	else if (ft_strcmp(words[0], "tr") == 0)
		parse_triangle(words, info);
	else
		print_error("Invalid line\n");
	free_string_arr(words);
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
		print_error("Invalid file extension\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Opening file went wrong\n");
	while (get_next_line(fd, &line))
	{
		if (*line != '#')
			parse_line(line, info);
		free(line);
	}
	if (!info->mapinfo.did_ambient || !info->mapinfo.did_resolution)
		print_error("Invalid file. R and A have to be present\n");
	/*if (!info->cameras || !info->lights)*/
		/*print_error("At least one camera and light should be defined\n");*/
	close(fd);
}
