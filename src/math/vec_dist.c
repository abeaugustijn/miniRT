/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:35:28 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/20 16:41:44 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

double	vec_dist(t_vec3f vec1, t_vec3f vec2)
{
	return (sqrt(pow(vec2.x - vec1.x, 2) + 
				pow(vec2.y - vec1.y, 2) +
				pow(vec2.z - vec1.z, 2)));
}
