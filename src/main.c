/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:23:08 by abe               #+#    #+#             */
/*   Updated: 2020/01/14 22:07:12 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <libft.h>
#include <liblist.h>

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 2 && argc != 3)
		print_error("Invalid amount of arguments\n");
	ft_bzero(&info, sizeof(info));
	parse_input(argv[1], &info);
}
