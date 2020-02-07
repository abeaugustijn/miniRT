/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:55:17 by abe               #+#    #+#             */
/*   Updated: 2020/02/07 11:56:49 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H
# include <miniRT.h>

bool	intersect_plane(t_object *pl, t_ray ray);
bool	intersect_sphere(t_object *sp, t_ray ray);

bool	(*g_intersectjump[])(t_object *, t_ray) = {
	&intersect_sphere,
	&intersect_plane
};

#endif
