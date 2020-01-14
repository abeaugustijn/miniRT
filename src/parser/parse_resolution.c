/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:36:49 by abe               #+#    #+#             */
/*   Updated: 2020/01/14 22:08:55 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
#include <libft.h>

void	parse_resolution(char **words, t_info *info)
{
	if (arrlen(words) != 3)
		print_error("Error while parsing resolution\n");
	if (!isdigit_string(words[1]) || !isdigit_string(words[2]))
		print_error("Invalid resolution values\n");
	info->mapinfo.res_x = ft_atoi(words[1]);
	info->mapinfo.res_y = ft_atoi(words[2]);
	if (!info->mapinfo.res_x || !info->mapinfo.res_y)
		print_error("Invalid resolution\n");
}
