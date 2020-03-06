/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:04:59 by abe               #+#    #+#             */
/*   Updated: 2020/03/06 11:23:31 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>
#include <assert.h>
#include <libftprintf.h>

void	test_vec_normalize()
{
	t_vec3f	vec;
	vec.x = -1;
	vec.y = 20;
	vec.z = 30;
	vec = vec_normalize(vec);
	assert(float_compare(vec.x, -1.0 / 30));
	assert(float_compare(vec.y, 20.0 / 30));
	assert(float_compare(vec.z, 1.0));

	vec.x = 10;
	vec.y = 10;
	vec.z = 10;
	vec = vec_normalize(vec);
	assert(float_compare(vec.x, 1.0));
	assert(float_compare(vec.y, 1.0));
	assert(float_compare(vec.z, 1.0));

	vec.x = 10;
	vec.y = 20;
	vec.z = 30;
	vec = vec_normalize(vec);
	assert(float_compare(vec.x, 1.0 / 3));
	assert(float_compare(vec.y, 2.0 / 3));
	assert(float_compare(vec.z, 1.0));
}

void	test_parse_double()
{
	double	res;

	res = parse_double("1.123");
	assert(float_compare(res, 1.123));
	res = parse_double("1");
	assert(float_compare(res, 1));
	res = parse_double("0");
	assert(float_compare(res, 0));
	res = parse_double("100");
	assert(float_compare(res, 100));
	res = parse_double("0.0001");
	assert(float_compare(res, 0.0001));
	res = parse_double("-10");
	assert(float_compare(res, -10));
}

void	test_crossp()
{
	t_vec3f	res;

	res = vec_crossp(vec_new(2, 3, 4), vec_new(5, 6, 7));
	assert(float_compare(res.x, -3));
	assert(float_compare(res.y, 6));
	assert(float_compare(res.z, -3));
}

void	test_points_line_closest()
{
	t_line 	a, b;
	t_vec3f	closest[2];
	double	t[2];

	a = ray_new(vec_new(0,0,0), vec_new(0,0,-1));
	b = ray_new(vec_new(1,0,-1), vec_new(0,1,0));
	points_line_closest(a, b, t);
	closest[0] = ray_point(a, t[0]);
	closest[1] = ray_point(b, t[1]);
	assert(vec_compare(closest[0], vec_new(0, 0, -1)));
	assert(vec_compare(closest[1], vec_new(1, 0, -1)));
	assert(float_compare(vec_dist(closest[0], closest[1]), 1));

	a = ray_new(vec_new(-3,2,1), vec_normalize(vec_new(0,2,3)));
	b = ray_new(vec_new(7,4,-2), vec_normalize(vec_new(-1,0,0)));
	points_line_closest(a, b, t);
	closest[0] = ray_point(a, t[0]);
	closest[1] = ray_point(b, t[1]);
	assert(float_compare(vec_dist(closest[0], closest[1]), 3.32820117735));
}

	#include <stdio.h>

int main()
{
	/*printf("test_vec_normalize()\n");*/
	/*test_vec_normalize();*/
	ft_printf("test_parse_double()\n");
	test_parse_double();
	ft_printf("test_crossp()\n");
	test_crossp();
	ft_printf("test_points_line_closest()\n");
	test_points_line_closest();
}
