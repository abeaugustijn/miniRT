/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_line_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:26:13 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/28 14:52:22 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

/*
**	DISTANCE BETWEEN LINE AND POINT:
**		d(line, point) = d(L, c)
**		// L is a point on the line
**		// c is the point
**	
**		* Decide L:
**		where d(L, c) is minimal
**		d(l(o) + x * l(d), c)
**		= d([ox, oy, oz] + x * [dx, dy, dz], [cx, cy, cz])
**		= d([ox + x * dx, oy + x * dy, oz + x * dz], [cx, cy, cz])
**		= sqrt((cx - (ox + x * dx)) ^ 2 +
**				(cy - (oy + x * dy)) ^ 2 +
**				(cz - (oz + x * dz)) ^ 2)
**		= sqrt((cx - ox - x * dx) ^ 2 +
**				(cy - oy - x * dy) ^ 2 +
**				(cz - oz - x * dz) ^ 2)
**		= sqrt(cx ^ 2 - cx * ox - cx * x * dx - ox * cx + ox ^ 2 + ox * x * dx -
**					x * dx * cx + x * dx * ox + x ^ 2 * dx ^ 2 +
**				cy ^ 2 - cy * oy - cy * x * dy - oy * cy + oy ^ 2 + oy * x * dy -
**					x * dy * cy + x * dy * oy + x ^ 2 * dy ^ 2 +
**				cz ^ 2 - cz * oz - cz * x * dz - oz * cz + oz ^ 2 + oz * x * dz -
**					x * dz * cz + x * dz * oz + x ^ 2 * dz ^ 2)
**		= sqrt((dx ^ 2 + dy ^ 2 + dz ^ 2) * x ^ 2 +
**					(-cx * dx - cy * dy - cz * dz
**					+ ox * dx + oy * dy + oz * dz
**					- cx * dx - cy * dy - cz * dz
**					+ dx * ox + dy * oy + dz * oz) * x +
**						- cx * ox - cy * oy - cz * oz
**						- cx * ox - cy * oy - cz * oz
**						+ ox ^ 2 + oy ^ 2 + oz ^ 2)
**		= sqrt((dx ^ 2 + dy ^ 2 + dz ^ 2) * x ^ 2 +
**					(- 2 * (cx * dx - cy * dy - cz * dz)
**					+ ox * dx + oy * dy + oz * dz
**					+ dx * ox + dy * oy + dz * oz) * x +
**						- 2 * (cx * ox - cy * oy - cz * oz)
**						+ ox ^ 2 + oy ^ 2 + oz ^ 2)
**	
**		Now we need the derivitive of this function and solve it against 0, to get
**		the value of x where the distance between L and c is smallest.
**	
**		//	f(x) = sqrt(g(x))
**		//	'f(x) = ('g(x)) / (2 * f(x))
**	
**		'd(L, c) = (2 * (dx ^ 2 + dy ^ 2 + dz ^ 2) * x
**					- 2 * (cx * dx + cy * dy + cz * dz)
**					+ 2 * (dx * ox + dy * oy + dz * oz)) / 
**					(2 * ((dx ^ 2 + dy ^ 2 + dz ^ 2) * x ^ 2 +
**						(- 2 * (cx * dx - cy * dy - cz * dz)
**						+ ox * dx + oy * dy + oz * dz
**						+ dx * ox + dy * oy + dz * oz) * x +
**							- 2 * (cx * ox - cy * oy - cz * oz)
**							+ ox ^ 2 + oy ^ 2 + oz ^ 2))
**	
**		Solve for 'd(L, c) = 0
**	
**		2 * (dx ^ 2 + dy ^ 2 + dz ^ 2) * x
**		- 2 * (cx * dx + cy * dy + cz * dz)
**		+ 2 * (dx * ox + dy * oy + dz * oz) = 0
**	
**		==> 
**	
**		2 * (dx ^ 2 + dy ^ 2 + dz ^ 2) * x = 
**		2 * (cx * dx + cy * dy + cz * dz)
**		- 2 * (dx * ox + dy * oy + dz * oz)
**		
**		==>
**	
**		x = (2 * (cx * dx + cy * dy + cz * dz)
**		- 2 * (dx * ox + dy * oy + dz * oz)) /
**		(2 * (dx ^ 2 + dy ^ 2 + dz ^ 2))
**	
**		where
**		
**		2 * ((dx ^ 2 + dy ^ 2 + dz ^ 2) * x ^ 2 +
**			(- 2 * (cx * dx - cy * dy - cz * dz)
**			+ ox * dx + oy * dy + oz * dz
**			+ dx * ox + dy * oy + dz * oz) * x +
**				- 2 * (cx * ox - cy * oy - cz * oz)
**				+ ox ^ 2 + oy ^ 2 + oz ^ 2) != 0
*/

bool	point_line_closest(t_ray ray, t_vec3f c, t_vec3f *res)
{
	double	x;
	t_vec3f	d;
	t_vec3f	o;
	double	to_check;

	d = ray.direction;
	o = ray.origin;
	x = 2 * (c.x * d.x + c.y * d.y + c.z * d.z);
	x -= 2 * (o.x * d.x + o.y *d.y + o.z * d.z);
	to_check = 2 * (pow(d.x, 2) + pow(d.y, 2) + pow(d.z, 2));
	if (to_check == 0)
		return (true);
	x /= to_check;
	if (x > 0)
		return (true);
	*res = vec_add(o, vec_multiply(d, x));
	return (false);
}
