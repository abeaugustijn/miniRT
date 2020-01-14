/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:22:53 by abe               #+#    #+#             */
/*   Updated: 2020/01/14 21:24:36 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/*
**	Checks whther a string exist of only digits.
**
**	@param {char *} string
**
**	@return {bool}
*/

bool	isdigit_string(char *string)
{
	while (*string)
	{
		if (!(*string >= '0' && *string <= '9'))
			return (false);
		string += sizeof(char);
	}
	return (true);
}
