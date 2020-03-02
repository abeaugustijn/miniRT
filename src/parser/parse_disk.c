
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/02/04 15:33:16 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <libft.h>

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

	if (arrlen(words) != 5)
		print_error("Error while parsing plane\n", info);
	ft_bzero(&res, sizeof(t_object));
	res.type = DS;
	res.location = parse_vec3f(words[1], info);
	res.orientation = vec_normalize(parse_vec3f(words[2], info));
	res.size = parse_double(words[3]);
	res.color = parse_color(words[4], info);
	if (vla_push(&info->objects, &res, NULL))
		print_error("Allocation failed in 'parse_disk'\n", info);
}
