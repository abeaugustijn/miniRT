/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread_info_new.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 12:54:24 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/06 12:02:48 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

t_thread_info	*thread_info_new(t_info *info, t_color *buf, uint32_t start)
{
	t_thread_info	*res;

	res = malloc(sizeof(t_thread_info));
	if (!res)
		print_error("Allocation failed in 'thread_info_new'", info);
	res->info = info;
	res->buf = buf;
	res->start = start;
	return (res);
}
