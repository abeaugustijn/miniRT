/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:10:48 by abe               #+#    #+#             */
/*   Updated: 2020/01/24 11:57:12 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
#include <stdlib.h>
#include <libft.h>

void			parse_light(char **words, t_info *info)
{
	t_light	*res;

	if (arrlen(words) != 4)
		print_error("Error while parsing light\n");
	res = (t_light *)malloc(sizeof(t_light));
	if (!res)
		print_error("Allocation failed in 'parse_light'\n");
	res->location = parse_vec3f(words[1]);
	res->brightness = parse_double(words[2]);
	if (res->brightness < 0 || res->brightness > 1)
		print_error_free("Invalid brightness for light\n", res);
	res->color = parse_color(words[3]);
	if (!lst_new_back(&(info->lights), res))
		print_error_free_list("Allocation failed in 'parse_light'\n", info->lights);
}
