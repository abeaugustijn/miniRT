/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 18:55:00 by abe           #+#   #+#                  */
/*   Updated: 2020/03/20 13:55:46 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <minirt.h>
#include <stdlib.h>

/*
**	Parse function for squares. Throws an error if orientation is not
**		normalized.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void	parse_square(char **words, t_info *info)
{
	t_object	res;
	t_object	*sq;

	if (parse_arrlen(words) != 5)
		print_error("Error while parsing square", info);
	ft_bzero(&res, sizeof(t_object));
	res.type = SQ;
	res.location = parse_vec3f(words[1], info);
	res.dir_vecs.forward = vec_normalize(parse_vec3f(words[2], info));
	res.size = parse_double(words[3]);
	if (res.size < 0)
		print_error("Invalid size for square", info);
	res.color = parse_color(words[4], info);
	if (vla_push(&info->objects, &res, (void **)&sq))
		print_error("Allocation failed in 'parse_square'", info);
	children_square_gen(sq, info);
	update(sq, info);
}
