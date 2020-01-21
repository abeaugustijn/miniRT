/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:36:51 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/20 15:40:02 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ray_calc_dir(t_ray *ray, t_vec3f cam)
{
	t_vec3f	res;

	res.x = ray->origin.x - cam.x;
	res.y = ray->origin.y - cam.y;
	res.z = ray->origin.z - cam.z;
	ray->direction = (vec3f_normalize(res));
}
