/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_words.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 20:18:57 by abe           #+#   #+#                  */
/*   Updated: 2020/03/20 13:48:52 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

/*
**	Free a NULL-terminated array of strings.
**
**	@param {char **}
*/

void	free_words(char **array)
{
	uint8_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
