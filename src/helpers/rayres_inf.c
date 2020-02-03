/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayres_inf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:17:21 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/03 16:13:34 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	Get an instance of the rayres struct, whith a distance of INFINITY.
**
**	@return {t_rayres}
*/

t_rayres	rayres_inf(void)
{
	return (rayres_new_dist(NULL, vec_new(0, 0, 0), col_new(0, 0, 0), INFINITY));
}
