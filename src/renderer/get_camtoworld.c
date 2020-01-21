/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camtoworld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:49:39 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/20 15:18:53 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>

t_mat4f	get_camtoworld(t_info *info)
{
	t_mat4f	res;

	ft_bzero(&res, sizeof(t_mat4f));
	(void)info;
	return (res);
}
