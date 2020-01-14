/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:47:37 by abe               #+#    #+#             */
/*   Updated: 2020/01/14 22:08:05 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
#include <libft.h>

void	parse_ambient(char **words, t_info *info)
{
	if (arrlen(words) != 3)
		print_error("Error while parsing ambient lighting\n");
	info->mapinfo.ambient_ratio = parse_float(words[1]);
	info->mapinfo.ambient_color = parse_color(words[2]);
}
