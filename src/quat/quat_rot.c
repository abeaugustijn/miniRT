/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:28:20 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/06 16:16:57 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec4f	quat_rot(t_vec3f orientation, t_vec3f rot_dir, double angle)
{
	t_vec4f	p[2];
	t_vec4f	r[2];

	p[0] = quat_new(1, orientation.x, orientation.y, orientation.z);
	r[0] = quat_rot_local(rot_dir, angle);
	r[1] = quat_inverse(r[0]);
	return (quat_multiply(quat_multiply(r[0], p[0]), r[1]));
}
