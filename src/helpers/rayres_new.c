/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayres_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:38:55 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/27 13:39:31 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_rayres	rayres_new(double dist, t_color color)
{
	t_rayres	res;

	res.dist = dist;
	res.color = color;
	return (res);
}
