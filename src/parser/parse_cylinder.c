/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 14:51:07 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <libft.h>

/*
**	Parse function for cylinders. Throws an error if orientation is not
**		normalized.
**
**	TODO: decide if we want to normalize orientation if it is not normalized
**		as input.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void	parse_cylinder(char **words, t_info *info)
{
	t_object	*res;

	if (arrlen(words) != 6)
		print_error("Error while parsing cylinder\n", info);
	res = (t_object *)malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'parse_cylinder'\n", info);
	ft_bzero(res, sizeof(t_object));
	res->type = CY;
	res->location = parse_vec3f(words[1], info);
	res->orientation = parse_vec3f(words[2], info);
	if (!check_normalized(res->orientation))
		print_error_free("Orientation vector for cylinder is not normalized\n", info, res, &free);
	res->size = parse_double(words[3]);
	if (res->size < 0)
		print_error_free("Invalid diameter for cylinder\n", info, res, &free);
	res->height = parse_double(words[4]);
	if (res->height < 0)
		print_error_free("Invalid height for cylinder\n", info, res, &free);
	res->color = parse_color(words[5], info);
	if (!lst_new_back(&(info->objects), res))
		print_error("Allocation failed in 'parse_cylinder'\n", info);
}
