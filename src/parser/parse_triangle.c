/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:55:00 by abe               #+#    #+#             */
/*   Updated: 2020/01/28 20:49:41 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>
#include <libft.h>

void	parse_triangle(char **words, t_info *info)
{
	t_object	*res;

	if (arrlen(words) != 5)
		print_error("Error while parsing triangle\n", info);
	res = (t_object *)malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'parse_triangle'\n", info);
	ft_bzero(res, sizeof(t_object));
	res->type = TR;
	res->points[0] = parse_vec3f(words[1], info);
	res->points[1] = parse_vec3f(words[2], info);
	res->points[2] = parse_vec3f(words[3], info);
	res->color = parse_color(words[4], info);
	if (!lst_new_back(&(info->objects), res))
		print_error("Allocation failed in 'parse_triangle'\n", info);
}
