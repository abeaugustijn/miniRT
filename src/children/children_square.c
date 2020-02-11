/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:25:01 by abe               #+#    #+#             */
/*   Updated: 2020/02/11 14:52:58 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>

/*
**	Initialize the children for the square object. The children will be two
**	triangles the square consists of. The parent fields in the object struct
**	will be set to the given square pointer.
**
**	@param {t_object *} sq
**	@param {t_info *} info - used in the print_error function
*/

void	children_square(t_object *sq, t_info *info)
{
	t_list	*added;
	uint8_t	i;

	i = 0;
	while (i < 2)
	{
		added = lst_new_back(&(info->objects), empty_object_type(info, TR));
		if (!added)
			print_error("Allocation failed in 'children_square'", info);
		((t_object *)added->content)->parent = sq;
		i++;
	}
	children_square_update(sq, info);
}

/*
**	Update the children of a square to account for new values of the suqare.
**	The children will be found by iterating over the objects list.
**
**	@param {t_object *} sq
**	@param {t_info *} info - used in the print_error function
*/

void	children_square_update(t_object *sq, t_info *info)
{
	t_object	*children[2];
	t_vec3f		points[4];

	find_children(sq, children, info);
	// TODO: gen points
	children[0]->points[0] = points[0];
	children[0]->points[1] = points[1];
	children[0]->points[2] = points[2];
	children[1]->points[0] = points[1];
	children[1]->points[1] = points[2];
	children[1]->points[2] = points[3];
}
