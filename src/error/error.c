/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:30:12 by abe               #+#    #+#             */
/*   Updated: 2020/01/28 20:30:49 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <stdlib.h>
#include <liblist.h>

void	print_error(char *message, t_info *info)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	free_info(info);
	exit(1);
}

void	print_error_free(char *message, t_info *info, void *to_free,
		void (*free_func)(void *))
{
	free(to_free);
	free_func(to_free);
	print_error(message, info);
}
