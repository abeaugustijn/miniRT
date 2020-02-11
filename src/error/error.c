/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:30:12 by abe               #+#    #+#             */
/*   Updated: 2020/02/11 15:42:17 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <stdlib.h>
#include <liblist.h>

/*
**	Print out an error, free all information in the info struct and exit the
**	process with exit code 1.
**
**	@param {char *} message
**	@param {t_info *} info
*/

void	print_error(char *message, t_info *info)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	if (info)
		free_info(info);
	exit(1);
}

/*
**	Print out an error, free the given pointer using the free function, free
**	all information in the info struct and exit the process with exit code 1.
**
**	@param {char *} message
**	@param {t_info *} info
**	@param {void *} to_free
**	@param {void *(void *)} free_func
*/

void	print_error_free(char *message, t_info *info, void *to_free,
		void (*free_func)(void *))
{
	free_func(to_free);
	print_error(message, info);
}
