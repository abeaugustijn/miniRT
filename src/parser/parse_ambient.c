/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 21:47:37 by abe           #+#   #+#                  */
/*   Updated: 2020/03/20 13:52:16 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <minirt.h>

/*
**	Parse function for the ambient lighting.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void	parse_ambient(char **words, t_info *info)
{
	if (parse_arrlen(words) != 3)
		print_error("Error while parsing ambient lighting", info);
	if (info->mapinfo.did_ambient)
		print_error("Invalid file. Ambient is specified multiple times.", info);
	info->mapinfo.ambient_ratio = parse_double(words[1]);
	info->mapinfo.ambient_color = parse_color(words[2], info);
	info->mapinfo.did_ambient = true;
}
