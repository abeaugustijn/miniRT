/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:31:31 by abe               #+#    #+#             */
/*   Updated: 2020/02/01 15:05:58 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>

void	free_info(t_info *info)
{
	if (info->cameras)
		free_list(info->cameras, &free);
	if (info->objects)
		free_list(info->objects, &free);
	if (info->lights)
		free_list(info->lights, &free);
}