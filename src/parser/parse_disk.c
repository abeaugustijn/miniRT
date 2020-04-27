/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_disk.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 18:55:00 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 14:19:24 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <minirt.h>
#include <stdlib.h>

/*
**	Parse function for disks.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void	parse_disk(char **words, t_info *info)
{
	t_object	res;
	t_object	*ds;

	if (parse_arrlen(words) != 5)
		print_error("Error while parsing plane", info);
	ft_bzero(&res, sizeof(t_object));
	res.type = DS;
	res.location = parse_vec3f(words[1], info);
	res.dir_vecs.forward = vec_normalize(parse_vec3f(words[2], info));
	res.size = parse_double(words[3]);
	res.color = parse_color(words[4], info);
	if (vla_push(&info->objects, &res, (void **)&ds))
		print_error("Allocation failed in 'parse_disk'", info);
	update(ds, info);
}
