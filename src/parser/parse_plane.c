/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/03/17 09:57:47 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <libft.h>

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

	if (arrlen(words) != 4)
		print_error("Error while parsing plane", info);
	ft_bzero(&res, sizeof(t_object));
	res.type = PL;
	res.location = parse_vec3f(words[1], info);
	res.dir_vecs.forward = vec_normalize(parse_vec3f(words[2], info));
	res.color = parse_color(words[3], info);
	if (vla_push(&info->objects, &res, NULL))
		print_error("Allocation failed in 'parse_plane'", info);
}
