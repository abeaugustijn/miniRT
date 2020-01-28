/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:29:55 by abe               #+#    #+#             */
/*   Updated: 2020/01/28 20:33:19 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblist.h>
#include <stdlib.h>

void	free_list(t_list *to_free, void (*free_func)(void *))
{
	t_list	*tmp;

	while (to_free)
	{
		tmp = to_free->next;
		free_func(to_free->content);
		free(to_free);
		to_free = tmp;
	}
}
