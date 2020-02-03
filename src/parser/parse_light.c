/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:10:48 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 14:45:36 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
#include <stdlib.h>
#include <libft.h>

/*
**	Parse function for the lights.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void			parse_light(char **words, t_info *info)
{
	t_light	*res;

	if (arrlen(words) != 4)
		print_error("Error while parsing light\n", info);
	res = (t_light *)malloc(sizeof(t_light));
	if (!res)
		print_error("Allocation failed in 'parse_light'\n", info);
	res->location = parse_vec3f(words[1], info);
	res->brightness = parse_double(words[2]);
	if (res->brightness < 0 || res->brightness > 1)
		print_error_free("Invalid brightness for light\n", info, res, &free);
	res->color = parse_color(words[3], info);
	if (!lst_new_back(&(info->lights), res))
		print_error("Allocation failed in 'parse_light'\n", info);
}
