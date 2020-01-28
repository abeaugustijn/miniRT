/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:31:31 by abe               #+#    #+#             */
/*   Updated: 2020/01/28 20:34:09 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdlib.h>

void	free_info(t_info *info)
{
	free_list(info->cameras, &free);
	free_list(info->objects, &free);
	free_list(info->lights, &free);
}
