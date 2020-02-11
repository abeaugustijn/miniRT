/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:25:01 by abe               #+#    #+#             */
/*   Updated: 2020/02/11 15:59:56 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
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
	t_vec3f	temp;
	uint8_t	i;

	temp = vec_multiply(vec_rot_x(sq->orientation, M_PI / 2), sq->size / 2);
	points[0] = vec_add(temp, vec_rot_z(temp, M_PI / 2));
	temp = vec_rot_z(temp, M_PI / 90);
	points[1] = vec_add(temp, vec_rot_z(temp, M_PI / 2));
	temp = vec_rot_z(temp, M_PI / 90);
	points[2] = vec_add(temp, vec_rot_z(temp, M_PI / 2));
	temp = vec_rot_z(temp, M_PI / 90);
	points[3] = vec_add(temp, vec_rot_z(temp, M_PI / 2));
	temp = vec_rot_z(temp, M_PI / 90);
	i = 0;
	while (i < 4)
	{
		points[i] = vec_add(sq->location, points[i]);
		i++;
	}
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
	children[1]->points[0] = points[1];
	children[1]->points[1] = points[2];
	children[1]->points[2] = points[3];
}

/*
**	Initialize the children for the square object. The children will be two
**	triangles the square consists of. The parent fields in the object struct
**	will be set to the given square pointer.
**
**	@param {t_object *} sq
**	@param {t_info *} info - used in the print_error function
*/

void		children_square(t_object *sq, t_info *info)
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
