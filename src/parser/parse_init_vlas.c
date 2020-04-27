/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_init_vlas.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/20 13:59:02 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 14:20:07 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libvla.h>
#include <minirt.h>

/*
**	Initialize all the VLAs for the parsing.
**
**	@param {t_info *} info
*/

void	parse_init_vlas(t_info *info)
{
	if (vla_init(sizeof(t_camera), 20, &info->cameras) ||
			vla_init(sizeof(t_light), 20, &info->lights) ||
			vla_init(sizeof(t_object), 20, &info->objects))
		print_error("Allocation failed in 'init_vlas'", info);
}
