/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:53:08 by abe               #+#    #+#             */
/*   Updated: 2020/01/20 11:47:30 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static float	get_max(t_vec3f vec)
{
	if (vec.x >= vec.y && vec.x >= vec.z)
		return (vec.x);
	if (vec.y >= vec.x && vec.y >= vec.z)
		return (vec.y);
	return (vec.z);
}

static float	get_min(t_vec3f vec)
{
	if (vec.x <= vec.y && vec.x <= vec.z)
		return (vec.x);
	if (vec.y <= vec.x && vec.y <= vec.z)
		return (vec.y);
	return (vec.z);
}

t_vec3f	vec3f_normalize(t_vec3f vec)
{
	float	max;
	float	min;
	bool	is_min;
	t_vec3f	res;

	max = get_max(vec);
	min = get_min(vec);
	is_min = (min < 0 && min * -1 > max);
	if (is_min)
	{
		res.x = vec.x / min;
		res.y = vec.y / min;
		res.z = vec.z / min;
	}
	else
	{
		res.x = vec.x / max;
		res.y = vec.y / max;
		res.z = vec.z / max;
	}
	return (res);
}
