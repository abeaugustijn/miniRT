/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:25:01 by abe               #+#    #+#             */
/*   Updated: 2020/03/02 16:46:01 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
#include <math.h>

/*
**	Update the children of a cylinder to account for new values of the cylinder.
**	The children will be found by iterating over the objects list.
**
**	@param {t_object *} cy
**	@param {t_info *} info - used in the print_error function
*/

void		children_cylinder_update(t_object *cy, t_info *info)
{
	t_object	*children[2];

	find_children(cy, children, info);
	children[0]->orientation = cy->orientation;
	children[1]->orientation = cy->orientation;
	children[0]->size = cy->size;
	children[1]->size = cy->size;
	children[0]->location = vec_add(cy->location, vec_multiply(cy->orientation,
				cy->height / 2));
	children[1]->location = vec_sub(cy->location, vec_multiply(cy->orientation,
				cy->height / 2));
	children[0]->color = cy->color;
	children[1]->color = cy->color;
}

/*
**	Initialize the children for the cylinder object. The children will be two
**	disks on top and bottom of the cylinder The parent fields in the object
**	struct will be set to the given cylinder pointer.
**
**	@param {t_object *} cy
**	@param {t_info *} info - used in the print_error function
*/

void		children_cylinder(t_object *cy, t_info *info)
{
	t_object	*added;
	uint8_t	i;

	i = 0;
	while (i < 2)
	{
		if (vla_push(&info->parser_vlas.objects, empty_object_type(info, DS),
					(void **)&added))
			print_error("Allocation failed in 'children_cylinder'", info);
		added->parent = cy;
		i++;
	}
	children_cylinder_update(cy, info);
}
