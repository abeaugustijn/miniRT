/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dotp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:27:47 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/27 15:29:08 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	vec_dotp(t_vec3f vec1, t_vec3f vec2)
{
	return (vec1.x * vec2.x +
			vec1.y * vec2.y +
			vec1.z * vec2.z);
}