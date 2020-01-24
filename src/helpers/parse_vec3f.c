/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec3f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:36:36 by abe               #+#    #+#             */
/*   Updated: 2020/01/24 11:56:41 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <stdbool.h>

/*
**	Parse a string with three floats, delimited by ',' chars into a vector.
*/

t_vec3f	parse_vec3f(char *str)
{
	t_vec3f	res;
	char	**words;

	words = ft_split(str, ',');
	if (!words)
		print_error("Allocation failed in 'parse_vec3f'\n");
	if (arrlen(words) != 3)
		print_error("Invalid amount of values in float vector\n");
	res.x = parse_double(words[0]);
	res.y = parse_double(words[1]);
	res.z = parse_double(words[2]);
	free_string_arr(words);
	return (res);
}
