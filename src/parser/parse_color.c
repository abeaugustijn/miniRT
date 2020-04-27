/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 21:36:36 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 14:19:07 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <minirt.h>
#include <stdbool.h>

static double	parse_color_part(char *part, t_info *info)
{
	double	res;

	res = parse_double(part);
	if (res < 0 || res > 255)
		print_error("Invalid color value", info);
	return (res);
}

/*
**	Parse a string with three integers, delimited by ',' chars into a color.
*/

t_color			parse_color(char *str, t_info *info)
{
	t_color	res;
	char	**words;

	words = ft_split(str, ',');
	if (!words)
		print_error("Allocation failed in 'parse_color'", info);
	if (parse_arrlen(words) != 3)
		print_error("Invalid amount of values in color vector", info);
	res.r = parse_color_part(words[0], info);
	res.g = parse_color_part(words[1], info);
	res.b = parse_color_part(words[2], info);
	free_words(words);
	return (res);
}
