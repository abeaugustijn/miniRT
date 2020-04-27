/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 20:30:12 by abe           #+#   #+#                  */
/*   Updated: 2020/03/06 11:59:19 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>

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
	ft_putstr_fd("\n", 1);
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

/*
**	Print out an error, free the given pointer array using the free function,
**	free all information in the info struct and exit the process with exit
**	code 1.
**
**	@param {char *} message
**	@param {t_info *} info
**	@param {void **} words
*/

void	print_error_free_words(char *message, t_info *info, char **words)
{
	free_words(words);
	print_error(message, info);
}

/*
**	Exit the program cleanly.
**
**	@param {t_info *} info
*/

void	exit_clean(t_info *info)
{
	if (info)
		free_info(info);
	exit(0);
}
