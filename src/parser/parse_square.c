/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/01/28 20:49:32 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <libft.h>

void	parse_square(char **words, t_info *info)
{
	t_object	*res;

	if (arrlen(words) != 5)
		print_error("Error while parsing square\n", info);
	res = (t_object *)malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'parse_square'\n", info);
	ft_bzero(res, sizeof(t_object));
	res->type = SQ;
	res->location = parse_vec3f(words[1], info);
	res->orientation = parse_vec3f(words[2], info);
	if (!check_normalized(res->orientation))
		print_error_free("Orientation vector for square is not normalized\n", info, res, &free);
	res->size = parse_float(words[3]);
	if (res->size < 0)
		print_error_free("Invalid size for square\n", info, res, &free);
	res->color = parse_color(words[4], info);
	if (!lst_new_back(&(info->objects), res))
		print_error("Allocation failed in 'parse_square'\n", info);
}
