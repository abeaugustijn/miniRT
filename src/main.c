/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 19:23:08 by abe           #+#   #+#                  */
/*   Updated: 2020/07/20 14:57:36 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_info		info;

	ft_bzero(&info, sizeof(t_info));
	if (argc == 2)
		print_error(
			"This version of miniRT can only be run with the --save flag",
			NULL);
	else if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
			print_error("Invalid argument given", NULL);
		else
			info.mapinfo.do_save = true;
	} else
		print_error("Invalid amount of arguments", NULL);
	parse_input(argv[1], &info);
	vla_get_addr(info.cameras, 0, (void **)&info.current_cam);
	save_bmp(&info);
	exit_clean(&info);
}
