/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:30:06 by abe               #+#    #+#             */
/*   Updated: 2020/01/15 18:49:39 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>
#include <stdbool.h>

/*
**	Parse a string to a float.
*/

float	parse_float(char *str)
{
	float	res;
	int		count;
	bool	is_neg;

	res = ft_atoi(str);
	is_neg = false;
	if (res < 0 || *str == '-')
	{
		str += sizeof(char);
		is_neg = true;
	}
	while (ft_isdigit(*str))
		str += sizeof(char);
	count = 1;
	if (*str != '.')
		return (res);
	str += sizeof(char);
	while (ft_isdigit(*str))
	{
		res += (((int)(*str - '0')) / pow(10, count)) * (is_neg ? -1 : 1);
		count++;
		str += sizeof(char);
	}
	return (res);
}
