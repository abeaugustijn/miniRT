/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:42:56 by abe               #+#    #+#             */
/*   Updated: 2020/03/02 18:43:02 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
**	Find the children of a certain object. An array pointer will be given to
**	store the results in. It is expected that this array has enough space to
**	store pointers to all children of the object.
**
**	@param {t_object *} ob - the object which children to find
**	@param {t_object **} to_store - the array in which to store the found
**		children.
**	@param {t_info *} info - used for getting the list of objects
*/

void	find_children(t_object *ob, t_object **to_store, t_info *info)
{
	t_object	*current;
	size_t		i;
	size_t		array_i;	

	i = 0;
	array_i = 0;
	while (!vla_get_addr(info->objects, i, (void **)&current))
	{
		if (current->parent == ob)
		{
			to_store[array_i] = current;
			array_i++;
		}
		i++;
	}
}
