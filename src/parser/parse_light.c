/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:10:48 by abe               #+#    #+#             */
/*   Updated: 2020/03/02 22:14:23 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
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
	t_light	res;

	if (arrlen(words) != 4)
		print_error("Error while parsing light\n", info);
	res.location = parse_vec3f(words[1], info);
	res.brightness = parse_double(words[2]);
	if (res.brightness < 0)
		print_error("Invalid brightness for light\n", info);
	res.color = parse_color(words[3], info);
	if (vla_push(&info->lights, &res, NULL))
		print_error("Allocation failed in 'parse_light'\n", info);
}
