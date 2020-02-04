/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:44:30 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/04 11:45:45 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Compare two floats to each other. When the difference between the two is
**	smaller than 10 ^ -5, 'true' will be returned.
**
**	@param {double} a
**	@param {double} b
**
**	@return {bool}
*/

bool	float_compare(double a, double b)
{
	double	abs;

	abs = a - b;
	if (abs < 0)
		abs *= -1;
	return (abs < 0.000001);
}

