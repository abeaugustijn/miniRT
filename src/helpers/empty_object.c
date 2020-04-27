/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_object.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 14:27:55 by abe           #+#   #+#                  */
/*   Updated: 2020/03/02 19:35:50 by abe           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>

/*
**	Allocate an empty object and initialize it with default values.
**
**	@param {t_info *} info - used in the print_error function
**
**	@return {t_object *}
*/

t_object	empty_object(void)
{
	t_object	res;

	ft_bzero(&res, sizeof(t_object));
	return (res);
}

/*
**	Allocate an empty object and initialize it with a certain type.
**
**	@param {t_info *} info - used in the print_error function
**	@param {t_object_type} type
**	@return {t_object *}
*/

t_object	empty_object_type(t_object_type type)
{
	t_object	res;

	ft_bzero(&res, sizeof(t_object));
	res.type = type;
	return (res);
}
