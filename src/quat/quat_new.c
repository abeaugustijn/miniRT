/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:21:48 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/06 15:55:41 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

inline t_vec4f	quat_new(double w, double x, double y, double z)
{
	return ((t_vec4f){w, x, y, z});
}
