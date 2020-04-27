/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 20:36:49 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 14:23:15 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <minirt.h>
#include <mlx.h>

/*
**	Checks whther a string exist of only digits.
**
**	@param {char *} string
**
**	@return {bool}
*/

static bool	isdigit_string(char *string)
{
	while (*string)
	{
		if (!(*string >= '0' && *string <= '9'))
			return (false);
		string += sizeof(char);
	}
	return (true);
}

/*
**	This is used to scale the resulotion down when it is too large for the
**	physical display.
**
**	@param {t_info *} info
*/

static void	parse_resolution_check_res(t_info *info)
{
	int	x;
	int	y;

	mlx_get_screen_size(info->mlx_info.mlx, &x, &y);
	if (info->mapinfo.res.x > x)
		info->mapinfo.res.x = x;
	if (info->mapinfo.res.y > y)
		info->mapinfo.res.y = y;
}

/*
**	Parse function for the resolution line.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void		parse_resolution(char **words, t_info *info)
{
	if (parse_arrlen(words) != 3)
		print_error("Error while parsing resolution", info);
	if (info->mapinfo.did_resolution)
		print_error("Invalid file. Resolution is specified multiple times",
				info);
	if (!isdigit_string(words[1]) || !isdigit_string(words[2]))
		print_error("Invalid resolution values", info);
	info->mapinfo.res.x = ft_atoi(words[1]);
	info->mapinfo.res.y = ft_atoi(words[2]);
	if (!info->mapinfo.res.x || !info->mapinfo.res.y)
		print_error("Invalid resolution", info);
	info->mapinfo.tot_pixels = info->mapinfo.res.x * info->mapinfo.res.y;
	info->mapinfo.did_resolution = true;
	if (!info->mapinfo.do_save)
		parse_resolution_check_res(info);
}
