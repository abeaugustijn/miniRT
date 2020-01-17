/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:23:08 by abe               #+#    #+#             */
/*   Updated: 2020/01/17 13:49:40 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <liblist.h>
#include <mlx.h>

int	main(int argc, char *argv[])
{
	t_info		info;
	t_mlxinfo	mlx_info;

	if (argc != 2 && argc != 3)
		print_error("Invalid amount of arguments\n");
	ft_bzero(&info, sizeof(info));
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
			print_error("Invalid argument given\n");
		else
			info.mapinfo.do_save = true;
	}
	parse_input(argv[1], &info);
	ft_bzero(&mlx_info, sizeof(t_mlxinfo));
	if (init_mlx(&mlx_info, &info))
		print_error("Error opening window\n");
	mlx_loop(mlx_info.mlx);
}
