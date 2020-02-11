/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:42:56 by abe               #+#    #+#             */
/*   Updated: 2020/02/11 14:48:36 by abe              ###   ########.fr       */
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
	t_list		*current;
	uint32_t	i;

	current = info->objects;
	i = 0;
	while (current)
	{
		if (((t_object *)current->content)->parent == ob)
		{
			to_store[i] = current->content;
			i++;
		}
		current = current->next;
	}
}
