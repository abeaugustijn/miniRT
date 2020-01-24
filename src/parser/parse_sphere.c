/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/01/24 11:57:19 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <libft.h>

void	parse_sphere(char **words, t_info *info)
{
	t_object	*res;

	if (arrlen(words) != 4)
		print_error("Error while parsing sphere\n");
	res = (t_object *)malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'parse_sphere'\n");
	ft_bzero(res, sizeof(t_object));
	res->type = SP;
	res->location = parse_vec3f(words[1]);
	res->size = parse_double(words[2]);
	if (res->size < 0)
		print_error_free("Invalid diameter for sphere\n", res);
	res->color = parse_color(words[3]);
	if (!lst_new_back(&(info->objects), res))
		print_error_free_list("Allocation failed in 'parse_sphere'\n", info->objects);
}
