/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children_square.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 14:25:01 by abe           #+#   #+#                  */
/*   Updated: 2020/03/17 19:06:20 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

/*
**	Calculate the coordinates of the 4 corners of a square.
**
**	@param {t_object *} sq
**	@param {t_vec3f *} points - an array to store the vectors in. This
**		array should be of the right size.
*/

static void	children_square_gen_points(t_object *sq, t_vec3f *points)
{
	t_vec3f	right;
	t_vec3f	up;

	up = vec_multiply(sq->dir_vecs.up, sq->size);
	right = vec_multiply(sq->dir_vecs.right, sq->size);
	points[0] = vec_add(vec_add(sq->location, up), right);
	points[1] = vec_add(vec_sub(sq->location, up), right);
	points[2] = vec_sub(vec_sub(sq->location, up), right);
	points[3] = vec_sub(vec_add(sq->location, up), right);
}

/*
**	Update the children of a square to account for new values of the suqare.
**	The children will be found by iterating over the objects list.
**
**	@param {t_object *} sq
**	@param {t_info *} info - used in the print_error function
*/

void		children_square_update(t_object *sq, t_info *info)
{
	t_object	*children[2];
	t_vec3f		points[4];

	find_children(sq, children, info);
	children_square_gen_points(sq, points);
	children[0]->points[0] = points[0];
	children[0]->points[1] = points[1];
	children[0]->points[2] = points[2];
	children[1]->points[0] = points[0];
	children[1]->points[1] = points[2];
	children[1]->points[2] = points[3];
	children[0]->color = sq->color;
	children[1]->color = sq->color;
}

/*
**	Initialize the children for the square object. The children will be two
**	triangles the square consists of. The parent fields in the object struct
**	will be set to the given square pointer.
**
**	@param {t_object *} sq
**	@param {t_info *} info - used in the print_error function
*/

void		children_square_gen(t_object *sq, t_info *info)
{
	t_object	empty;
	uint8_t		i;

	empty = empty_object_type(TR);
	empty.has_parent = true;
	empty.parent_i = vla_get_index(info->objects, sq, NULL);
	i = 0;
	while (i < 2)
	{
		if (vla_push(&info->objects, &empty, NULL))
			print_error("Allocation failed in 'children_square'", info);
		i++;
	}
}
