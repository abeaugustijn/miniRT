/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 14:46:12 by aaugusti         ###   ########.fr       */
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
	t_object	*res;

	if (arrlen(words) != 4)
		print_error("Error while parsing plane\n", info);
	res = (t_object *)malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'parse_plane'\n", info);
	ft_bzero(res, sizeof(t_object));
	res->type = PL;
	res->location = parse_vec3f(words[1], info);
	res->orientation = parse_vec3f(words[2], info);
	if (!check_normalized(res->orientation))
		print_error_free("Orientation vector for plane is not normalized\n", info, res, &free);
	res->color = parse_color(words[3], info);
	if (!lst_new_back(&(info->objects), res))
		print_error("Allocation failed in 'parse_plane'\n", info);
}
