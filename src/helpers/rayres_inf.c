/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rayres_inf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 13:17:21 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/10 14:38:28 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

/*
**	Get an instance of the rayres struct, whith a distance of INFINITY.
**
**	@return {t_rayres}
*/

inline t_rayres	rayres_inf(void)
{
	return (rayres_new(NULL, vec_new(0, 0, 0), INFINITY, vec_new(0, 0, 0)));
}
