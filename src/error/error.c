/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:30:12 by abe               #+#    #+#             */
/*   Updated: 2020/01/15 18:43:38 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <liblist.h>

void	print_error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	exit(1);
}

void	print_error_free(char *message, void *to_free)
{
	free(to_free);
	print_error(message);
}

void	print_error_free_list(char *message, t_list *to_free)
{
	t_list	*tmp;

	while (to_free)
	{
		tmp = to_free->next;
		free(to_free->content);
		free(to_free);
		to_free = tmp;
	}
	print_error(message);
}
