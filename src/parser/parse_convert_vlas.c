/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_convert_vlas.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/20 13:59:58 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/20 14:00:22 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libvla.h>
#include <minirt.h>

/*
**	Convert all VLAs to arrays.
**
**	@param {t_info *} info
*/

void	parse_convert_vlas(t_info *info)
{
	if (vla_shrink(&info->cameras) ||
		vla_shrink(&info->lights) ||
		vla_shrink(&info->objects))
		print_error("Allocation failed in 'convert_vlas'", info);
}
