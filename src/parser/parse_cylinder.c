/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cylinder.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 18:55:00 by abe           #+#   #+#                  */
/*   Updated: 2020/03/20 13:53:15 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <minirt.h>
#include <stdlib.h>

/*
**	Parse function for cylinders. Throws an error if orientation is not
**		normalized.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void	parse_cylinder(char **words, t_info *info)
{
	t_object	res;
	t_object	*cy;

	if (parse_arrlen(words) != 6)
		print_error("Error while parsing cylinder", info);
	ft_bzero(&res, sizeof(t_object));
	res.type = CY;
	res.location = parse_vec3f(words[1], info);
	res.dir_vecs.forward = vec_normalize(parse_vec3f(words[2], info));
	res.size = parse_double(words[3]);
	if (res.size < 0)
		print_error("Invalid diameter for cylinder", info);
	res.height = parse_double(words[4]);
	if (res.height < 0)
		print_error("Invalid height for cylinder", info);
	res.color = parse_color(words[5], info);
	if (vla_push(&info->objects, &res, (void **)&cy))
		print_error("Allocation failed in 'parse_cylinder'", info);
	children_cylinder_gen(cy, info);
	update(cy, info);
}
