/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_dir_vecs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 10:24:42 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/17 15:35:23 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <math.h>

void	update_dir_vecs(t_dir_vecs *vecs)
{
	if (float_compare(fabs(vecs->forward.y), 1))
		vecs->forward =vec_normalize(vec_new(
				vecs->forward.x, vecs->forward.y, vecs->forward.z + EPSILON));
	vecs->right = vec_normalize(vec_crossp(vec_new(0, 1, 0), vecs->forward));
	vecs->up = vec_normalize(vec_crossp(vecs->forward, vecs->right));
}
