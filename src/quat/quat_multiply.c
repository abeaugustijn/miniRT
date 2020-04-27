/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_multiply.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 16:17:07 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/06 16:19:27 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec4f	quat_multiply(t_vec4f a, t_vec4f b)
{
	return ((t_vec4f){
		.w = ((a.w * b.w) - (a.x * b.x) - (a.y * b.y) - (a.z * b.z)),
		.x = ((a.w * b.x) + (a.x * b.w) + (a.y * b.z) - (a.z * b.y)),
		.y = ((a.w * b.y) - (a.x * b.z) + (a.y * b.w) + (a.z * b.x)),
		.z = ((a.w * b.z) + (a.x * b.y) - (a.y * b.x) + (a.z * b.w))});
}
