/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:10:48 by abe               #+#    #+#             */
/*   Updated: 2020/01/14 22:45:17 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <liblist.h>
#include <stdlib.h>
#include <libft.h>

static uint8_t	check_fov(char *str)
{
	int	val;

	val = ft_atoi(str);
	if (val < 0 || val > 180)
		print_error("Errorwhile parsing camera: invalid FOV\n");
	return ((uint8_t)val);
}

void			parse_camera(char **words, t_info *info)
{
	t_camera	*res;

	if (arrlen(words) != 4)
		print_error("Error while parsing camera\n");
	res = (t_camera *)malloc(sizeof(t_camera));
	if (!res)
		print_error("Allocation failed in 'parse_camera'\n");
	res->location = parse_vec3f(words[1]);
	res->orientation = parse_vec3f(words[2]);
	if (!check_normalized(res->orientation))
		print_error(
				"Error while parsing camera: orientation vector is not normalized\n");
	res->fov = check_fov(words[3]);
	if (!info->cameras)
		info->cameras = lst_new_back(NULL, res);
	else
		lst_new_back(info->cameras, res);
	// TODO: malloc check (improve lst_new_back)
	/*if (!lst_new_back(info->cameras, res))*/
		/*print_error("Allocation failed in 'parse_camera'\n");*/
}
