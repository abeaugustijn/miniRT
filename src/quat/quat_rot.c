/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_rot.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:28:20 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/20 13:13:33 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec4f	quat_rot(t_vec3f orientation, t_vec3f rot_dir, double angle)
{
	t_vec4f	p;
	t_vec4f	q;
	t_vec4f	q_inv;

	p = quat_new(0, orientation.x, orientation.y, orientation.z);
	q = quat_rot_local(rot_dir, angle);
	q_inv = quat_inverse(q);
	return (quat_multiply(quat_multiply(q, p), q_inv));
}
