/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:17:52 by abe               #+#    #+#             */
/*   Updated: 2020/01/13 21:23:42 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**	Add a new node to the end of a list.
**
**	@param {t_list *} node - the first node of the list to add the new node to
**	@param {void *} content - the content of the new node
**
**	@return {t_list *} - the pointer to the new node. NULL if something went
**		wrong.
*/

t_list	*lst_new_back(t_list *node, void *content)
{
	t_list	*new;

	if (!node)
		return (lst_new(content));
	while (node->next)
		node = node->next;
	new = lst_new(content);
	new->prev = node;
	node->next = new;
	return (new);
}
