/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayres_inf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:17:21 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/28 21:16:55 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

t_rayres	rayres_inf(void)
{
	return (rayres_new_dist(NULL, vec_new(0, 0, 0), col_new(0, 0, 0), INFINITY));
}
