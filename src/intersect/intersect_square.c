/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:46:01 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/11 15:54:22 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Calculate whether a given ray intersects with a square.
**
**	@param {t_object *} sq (square)
**	@param {t_ray} ray
**	@param {t_info *} info
**
**	@return {bool} - true if intersect
*/

bool	intersect_square(t_object *sp, t_ray ray, t_info *info)
{
	t_object	*children[2];

	find_children(sp, children, info);
	return (intersect(children[0], ray, info) || intersect(children[1], ray, info));
}
