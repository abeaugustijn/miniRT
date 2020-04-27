/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_plane.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 18:55:00 by abe           #+#   #+#                  */
/*   Updated: 2020/03/20 13:54:23 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <minirt.h>
#include <stdlib.h>

/*
**	Parse function for planes.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void	parse_plane(char **words, t_info *info)
{
	t_object	res;
	t_object	*pl;

	if (parse_arrlen(words) != 4)
		print_error("Error while parsing plane", info);
	ft_bzero(&res, sizeof(t_object));
	res.type = PL;
	res.location = parse_vec3f(words[1], info);
	res.dir_vecs.forward = vec_normalize(parse_vec3f(words[2], info));
	res.color = parse_color(words[3], info);
	if (vla_push(&info->objects, &res, (void **)&pl))
		print_error("Allocation failed in 'parse_plane'", info);
	update(pl, info);
}
