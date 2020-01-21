/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:04:59 by abe               #+#    #+#             */
/*   Updated: 2020/01/20 14:06:51 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
#include <assert.h>

bool	compare(float a, float b)
{
	float	abs;

	abs = a - b;
	if (abs < 0)
		abs *= -1;
	return (abs < 0.000001);
}

void	test_vec_normalize()
{
	t_vec3f	vec;
	vec.x = -1;
	vec.y = 20;
	vec.z = 30;
	vec = vec3f_normalize(vec);
	assert(compare(vec.x, -1.0 / 30));
	assert(compare(vec.y, 20.0 / 30));
	assert(compare(vec.z, 1.0));

	vec.x = 10;
	vec.y = 10;
	vec.z = 10;
	vec = vec3f_normalize(vec);
	assert(compare(vec.x, 1.0));
	assert(compare(vec.y, 1.0));
	assert(compare(vec.z, 1.0));

	vec.x = 10;
	vec.y = 20;
	vec.z = 30;
	vec = vec3f_normalize(vec);
	assert(compare(vec.x, 1.0 / 3));
	assert(compare(vec.y, 2.0 / 3));
	assert(compare(vec.z, 1.0));
}

int main()
{
	test_vec_normalize();
}
