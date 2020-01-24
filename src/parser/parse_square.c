/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/01/24 11:57:25 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <libft.h>

void	parse_square(char **words, t_info *info)
{
	t_object	*res;

	if (arrlen(words) != 5)
		print_error("Error while parsing square\n");
	res = (t_object *)malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'parse_square'\n");
	ft_bzero(res, sizeof(t_object));
	res->type = SQ;
	res->location = parse_vec3f(words[1]);
	res->orientation = parse_vec3f(words[2]);
	if (!check_normalized(res->orientation))
		print_error_free("Orientation vector for square is not normalized\n", res);
	res->size = parse_double(words[3]);
	if (res->size < 0)
		print_error_free("Invalid size for square\n", res);
	res->color = parse_color(words[4]);
	if (!lst_new_back(&(info->objects), res))
		print_error_free_list("Allocation failed in 'parse_square'\n", info->objects);
}
