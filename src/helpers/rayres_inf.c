/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayres_inf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:17:21 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/27 13:28:16 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres	rayres_inf(void)
{
	t_rayres	res;

	res.dist = INFINITY;
	res.color = col_new(0, 0, 0);
	return (res);
}
