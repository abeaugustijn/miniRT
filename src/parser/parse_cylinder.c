/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/01/24 11:57:03 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <libft.h>

void	parse_cylinder(char **words, t_info *info)
{
	t_object	*res;

	if (arrlen(words) != 6)
		print_error("Error while parsing cylinder\n");
	res = (t_object *)malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'parse_cylinder'\n");
	ft_bzero(res, sizeof(t_object));
	res->type = CY;
	res->location = parse_vec3f(words[1]);
	res->orientation = parse_vec3f(words[2]);
	if (!check_normalized(res->orientation))
		print_error_free("Orientation vector for cylinder is not normalized\n", res);
	res->size = parse_double(words[3]);
	if (res->size < 0)
		print_error_free("Invalid diameter for cylinder\n", res);
	res->height = parse_double(words[4]);
	if (res->height < 0)
		print_error_free("Invalid height for cylinder\n", res);
	res->color = parse_color(words[5]);
	if (!lst_new_back(&(info->objects), res))
		print_error_free_list("Allocation failed in 'parse_cylinder'\n", info->objects);
}
