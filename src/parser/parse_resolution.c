/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:36:49 by abe               #+#    #+#             */
/*   Updated: 2020/02/25 15:19:08 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
#include <libft.h>

/*
**	Parse function for the resolution line.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void	parse_resolution(char **words, t_info *info)
{
	if (arrlen(words) != 3)
		print_error("Error while parsing resolution\n", info);
	if (info->mapinfo.did_resolution)
		print_error("Invalid file. Resolution is specified multiple times.", info);
	if (!isdigit_string(words[1]) || !isdigit_string(words[2]))
		print_error("Invalid resolution values\n", info);
	info->mapinfo.res.x = ft_atoi(words[1]);
	info->mapinfo.res.y = ft_atoi(words[2]);
	if (!info->mapinfo.res.x || !info->mapinfo.res.y)
		print_error("Invalid resolution\n", info);
	info->mapinfo.tot_pixels = info->mapinfo.res.x * info->mapinfo.res.y;
	info->mapinfo.did_resolution = true;
}
