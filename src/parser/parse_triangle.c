/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_triangle.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 18:55:00 by abe           #+#   #+#                  */
/*   Updated: 2020/03/20 13:55:51 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <minirt.h>
#include <stdlib.h>

/*
**	Parse function for triangles.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void	parse_triangle(char **words, t_info *info)
{
	t_object	res;

	if (parse_arrlen(words) != 5)
		print_error("Error while parsing triangle", info);
	ft_bzero(&res, sizeof(t_object));
	res.type = TR;
	res.points[0] = parse_vec3f(words[1], info);
	res.points[1] = parse_vec3f(words[2], info);
	res.points[2] = parse_vec3f(words[3], info);
	res.color = parse_color(words[4], info);
	if (vla_push(&info->objects, &res, NULL))
		print_error("Allocation failed in 'parse_triangle'", info);
}
