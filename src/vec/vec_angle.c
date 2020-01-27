/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:30:49 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/27 15:32:51 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

double	vec_angle(t_vec3f vec1, t_vec3f vec2)
{
	double	res;
	
	res = vec_dotp(vec1, vec2);
	res /= vec_len(vec1) * vec_len(vec2);
	res = acos(res);
	return (res);
}
