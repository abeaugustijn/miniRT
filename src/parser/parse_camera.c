/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:10:48 by abe               #+#    #+#             */
/*   Updated: 2020/03/20 13:52:27 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <miniRT.h>
#include <stdlib.h>

/*
**	Parse and check the fov value of the camera. Throws an error and exists if
**		fov falls in invalid range.
**
**	@param {char *} str - the string containing the fov value
**	@param {t_info *} info
**
**	@return {uint8_t} - the fov value
*/

static uint8_t	check_fov(char *str, t_info *info)
{
	int	val;

	val = ft_atoi(str);
	if (val < 0 || val > 180)
		print_error("Error while parsing camera: invalid FOV", info);
	return ((uint8_t)val);
}

/*
**	Parse function for cameras. This will also check whether the orientation
**		vector of the camera is normalized.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void			parse_camera(char **words, t_info *info)
{
	t_camera	res;

	if (parse_arrlen(words) != 4)
		print_error("Error while parsing camera\n", info);
	res.location = parse_vec3f(words[1], info);
	res.orientation = vec_normalize(parse_vec3f(words[2], info));
	res.fov = check_fov(words[3], info);
	cam_update(&res);
	if(vla_push(&info->cameras, &res, NULL))
		print_error("Allocation failed in 'parse_camera'\n", info);
}
