/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 18:55:00 by abe           #+#   #+#                  */
/*   Updated: 2020/03/20 13:55:42 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <minirt.h>
#include <stdlib.h>

/*
**	Parse function for spheres.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void	parse_sphere(char **words, t_info *info)
{
	t_object	res;

	if (parse_arrlen(words) != 4)
		print_error("Error while parsing sphere", info);
	ft_bzero(&res, sizeof(t_object));
	res.type = SP;
	res.location = parse_vec3f(words[1], info);
	res.size = parse_double(words[2]);
	if (res.size < 0)
		print_error("Invalid diameter for sphere", info);
	res.color = parse_color(words[3], info);
	if (vla_push(&info->objects, &res, NULL))
		print_error("Allocation failed in 'parse_sphere'", info);
}
