/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:21:16 by abe               #+#    #+#             */
/*   Updated: 2020/01/14 11:09:52 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <error.h>
#include <fcntl.h>
#include <unistd.h>
#include <get_next_line.h>

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
*/

static void	parse_line(char *line, t_mapinfo *mapinfo)
{
	
}

/*
**	Parse a *.rt file for use as input for miniRT.
**
**	@param {char *} filename
**	@param {t_mapinfo *} - a pointer to the mapinfo struct to store the parsed
**		data in.
*/

void		parse_input(char *filename, t_mapinfo *mapinfo)
{
	int		fd;
	char	*line;

	if (check_filename(filename))
		error("Invalid file extension\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Opening file went wrong\n");
	while (get_next_line(fd, &line))
	{
		parse_line(line, t_mapinfo *mapinfo);
		free(line);
	}
	// TODO: Check mapinfo
	close(fd);
}
