/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/01/15 22:37:48 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <libft.h>

void	parse_plane(char **words, t_info *info)
{
	t_object	*res;

	if (arrlen(words) != 4)
		print_error("Error while parsing plane\n");
	res = (t_object *)malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'parse_plane'\n");
	ft_bzero(res, sizeof(t_object));
	res->type = PL;
	res->location = parse_vec3f(words[1]);
	res->orientation = parse_vec3f(words[2]);
	if (!check_normalized(res->orientation))
		print_error_free("Orientation vector for plane is not normalized\n", res);
	res->color = parse_color(words[3]);
	if (!lst_new_back(&(info->objects), res))
		print_error_free_list("Allocation failed in 'parse_plane'\n", info->objects);
}
