/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec3f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:36:36 by abe               #+#    #+#             */
/*   Updated: 2020/01/28 16:08:45 by aaugusti         ###   ########.fr       */
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
	char	**words __attribute__ ((__cleanup__(free_string_arr)));

	words = ft_split(str, ',');
	if (!words)
		print_error("Allocation failed in 'parse_vec3f'\n");
	if (arrlen(words) != 3)
		print_error("Invalid amount of values in float vector\n");
	return (vec_new(parse_float(words[0]), parse_float(words[1]),
				parse_float(words[2])));
}
