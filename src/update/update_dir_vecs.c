/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_dir_vecs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti </var/spool/mail/abe>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 10:24:42 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/17 10:25:22 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	update_dir_vecs(t_dir_vecs *vecs)
{
	t_vec3f	base;

	base = float_compare(vecs->forward.y, 1) ?
		vec_new(1, 0, 0) : vec_new(0, 1, 0);
	vecs->right = vec_normalize(vec_crossp(base, vecs->forward));
	vecs->up = vec_normalize(vec_crossp(vecs->forward, vecs->right));
}
