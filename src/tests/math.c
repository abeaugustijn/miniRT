/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:04:59 by abe               #+#    #+#             */
/*   Updated: 2020/01/20 11:49:05 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
#include <assert.h>

bool	compare(float a, float b, float eps)
{
	return (fabs(a - b) < eps);
}

void	test_vec_normalize()
{
	t_vec3f	vec;
	vec.x = -1;
	vec.y = 20;
	vec.z = 30;
	vec = vec3f_normalize(vec);
	assert(compare(vec.x, -1 / 30, 0.000001));
}

int main()
{
	test_vec_normalize();
}
