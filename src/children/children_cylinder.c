/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children_cylinder.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 14:25:01 by abe           #+#   #+#                  */
/*   Updated: 2020/04/06 12:17:07 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
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
	children[0]->dir_vecs.forward = cy->dir_vecs.forward;
	children[1]->dir_vecs.forward = cy->dir_vecs.forward;
	children[0]->size = cy->size;
	children[1]->size = cy->size;
	children[0]->location = vec_add(cy->location,
			vec_multiply(cy->dir_vecs.forward, cy->height / 2));
	children[1]->location = vec_sub(cy->location,
			vec_multiply(cy->dir_vecs.forward, cy->height / 2));
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

void		children_cylinder_gen(t_object *cy, t_info *info)
{
	t_object	empty;
	uint8_t		i;

	empty = empty_object_type(DS);
	empty.has_parent = true;
	empty.parent_i = vla_get_index(info->objects, cy, NULL);
	i = 0;
	while (i < 2)
	{
		if (vla_push(&info->objects, &empty, NULL))
			print_error("Allocation failed in 'children_cylinder'", info);
		i++;
	}
}
