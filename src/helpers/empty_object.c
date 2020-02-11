/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:27:55 by abe               #+#    #+#             */
/*   Updated: 2020/02/11 14:34:40 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <stdlib.h>

/*
**	Allocate an empty object and initialize it with default values.
**
**	@param {t_info *} info - used in the print_error function
**
**	@return {t_object *}
*/

t_object	*empty_object(t_info *info)
{
	t_object	*res;

	res = malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'empty_object'\n", info);
	ft_bzero(res, sizeof(t_object));
	return (res);
}

/*
**	Allocate an empty object and initialize it with a certain type.
**
**	@param {t_info *} info - used in the print_error function
**	@param {t_object_type} type
**	@return {t_object *}
*/

t_object	*empty_object_type(t_info *info, t_object_type type)
{
	t_object	*res;

	res = malloc(sizeof(t_object));
	if (!res)
		print_error("Allocation failed in 'empty_object'\n", info);
	ft_bzero(res, sizeof(t_object));
	res->type = type;
	return (res);
}
