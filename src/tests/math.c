/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:04:59 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 14:25:09 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
#include <assert.h>

bool	compare(double a, double b)
{
	double	abs;

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

void	test_parse_double()
{
	double	res;

	res = parse_double("1.123");
	assert(compare(res, 1.123));
	res = parse_double("1");
	assert(compare(res, 1));
	res = parse_double("0");
	assert(compare(res, 0));
	res = parse_double("100");
	assert(compare(res, 100));
	res = parse_double("0.0001");
	assert(compare(res, 0.0001));
	res = parse_double("-10");
	assert(compare(res, -10));
}

	#include <stdio.h>

int main()
{
	printf("test_vec_normalize()\n");
	test_vec_normalize();
	printf("test_parse_double()\n");
	test_parse_double();
}
