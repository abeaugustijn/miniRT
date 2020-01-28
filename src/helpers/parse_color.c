/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:36:36 by abe               #+#    #+#             */
/*   Updated: 2020/01/28 16:06:44 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <stdbool.h>

static uint8_t	parse_color_part(char *part)
{
	int	res;
	res = ft_atoi(part);
	if (res < 0 || res > 255)
		print_error("Invalid color value\n");
	return ((uint8_t)res);
}

/*
**	Parse a string with three integers, delimited by ',' chars into a color.
*/

t_color	parse_color(char *str)
{
	t_color	res;
	char	**words __attribute__ ((__cleanup__(free_string_arr)));

	words = ft_split(str, ',');
	if (!words)
		print_error("Allocation failed in 'parse_color'\n");
	if (arrlen(words) != 3)
		print_error("Invalid amount of values in color vector\n");
	res.r = parse_color_part(words[0]);
	res.g = parse_color_part(words[1]);
	res.b = parse_color_part(words[2]);
	return (res);
}
