/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:10:48 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 14:44:56 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
#include <stdlib.h>
#include <libft.h>

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
		print_error("Error while parsing camera: invalid FOV\n", info);
	return ((uint8_t)val);
}

/*
**	Parse function for cameras. This will also check whether the orientation
**		vector of the camera is normalized.
**
**	TODO: decide if we want to normalize orientation if it is not normalized
**		as input.
**
**	@param {char **} words - array of strings, which are just the words of the
**		line, splitted on spaces.
**	@param {t_info *} info
*/

void			parse_camera(char **words, t_info *info)
{
	t_camera	*res;

	if (arrlen(words) != 4)
		print_error("Error while parsing camera\n", info);
	res = (t_camera *)malloc(sizeof(t_camera));
	if (!res)
		print_error("Allocation failed in 'parse_camera'\n", info);
	res->location = parse_vec3f(words[1], info);
	res->orientation = parse_vec3f(words[2], info);
	if (!check_normalized(res->orientation))
		print_error_free(
				"Error while parsing camera: orientation vector is not normalized\n", info, res, &free);
	res->fov = check_fov(words[3], info);
	if (!lst_new_back(&(info->cameras), res))
		print_error("Allocation failed in 'parse_camera'\n", info);
}
