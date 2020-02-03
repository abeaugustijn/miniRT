/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec3f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:36:36 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 14:24:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <stdbool.h>

/*
**	Parse a string with three doubles, delimited by ',' chars into a vector.
**
**	@param {char *} str
**	@param {t_info *} info - a pointer to the info struct for printing errors
**
**	@return {t_vec3f} - either returns the vector or exists while printing an
**		error.
*/

t_vec3f	parse_vec3f(char *str, t_info *info)
{
	char	**words __attribute__ ((__cleanup__(free_string_arr)));

	words = ft_split(str, ',');
	if (!words)
		print_error("Allocation failed in 'parse_vec3f'\n", info);
	if (arrlen(words) != 3)
		print_error("Invalid amount of values in vector\n", info);
	return (vec_new(parse_double(words[0]), parse_double(words[1]),
				parse_double(words[2])));
}
