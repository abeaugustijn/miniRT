/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_inside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:12:43 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/11 12:14:05 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Checks whether a given point falls inside of a triangle.
**
**	@param {t_object *} tr
**	@param {t_vec3f} tr_normal
**	@param {t_vec3f} p
**
**	@return {bool} - true if the point falls inside the triangle
*/

bool		triangle_inside(t_object *tr, t_vec3f tr_normal, t_vec3f p)
{
	t_vec3f	edges[3];
	t_vec3f	c[3];

	edges[0] = vec_sub(tr->points[1], tr->points[0]);
	edges[1] = vec_sub(tr->points[2], tr->points[1]);
	edges[2] = vec_sub(tr->points[0], tr->points[2]);
	c[0] = vec_sub(p, tr->points[0]);
	c[1] = vec_sub(p, tr->points[1]);
	c[2] = vec_sub(p, tr->points[2]);
	return (vec_dotp(tr_normal, vec_crossp(edges[0], c[0])) > 0 &&
				vec_dotp(tr_normal, vec_crossp(edges[1], c[1])) > 0 &&
				vec_dotp(tr_normal, vec_crossp(edges[2], c[2])) > 0);
}

