/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:23:08 by abe               #+#    #+#             */
/*   Updated: 2020/02/03 14:28:40 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <liblist.h>
#include <mlx.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_info		info;

	if (argc != 2 && argc != 3)
		print_error("Invalid amount of arguments\n", &info);
	ft_bzero(&info, sizeof(t_info));
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
			print_error("Invalid argument given\n", &info);
		else
			info.mapinfo.do_save = true;
	}
	parse_input(argv[1], &info);
	if (init_mlx(&info))
		print_error("Error opening window\n", &info);
	info.current_cam = info.cameras->content;
	mlx_loop(info.mlx_info.mlx);
}
