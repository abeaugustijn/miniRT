/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:49:06 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/21 14:50:33 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

void	resize_cylinder(t_object *cy, bool increase, t_info *info)
{
	(void)info;
	cy->size *= pow(RESIZE_SPEED, increase ? 1 : -1);
}
