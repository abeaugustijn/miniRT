/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:37:50 by abe               #+#    #+#             */
/*   Updated: 2020/03/20 13:40:31 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
**	Count the amount of elements in a NULL-terminated string array.
**
**	@param {char **} array
**
**	@return {size_t}
*/

size_t	parse_arrlen(char **array)
{
	size_t	res;

	res = 0;
	while (array[res])
		res++;
	return (res);
}

