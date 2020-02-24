/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:34:10 by abe               #+#    #+#             */
/*   Updated: 2020/02/24 12:22:36 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSE_FUNCTIONS_H
# define PARSE_FUNCTIONS_H
# include <miniRT.h>
# include <liblist.h>

typedef struct	s_parsefunc {
	char	*identifier;
	void	(*func)(char **, t_info *);
}				t_parsefunc;

void			parse_resolution(char **words, t_info *info);
void			parse_ambient(char **words, t_info *info);
void			parse_camera(char **words, t_info *info);
void			parse_light(char **words, t_info *info);
void			parse_sphere(char **words, t_info *info);
void			parse_plane(char **words, t_info *info);
void			parse_square(char **words, t_info *info);
void			parse_cylinder(char **words, t_info *info);
void			parse_triangle(char **words, t_info *info);
void			parse_disk(char **words, t_info *info);

t_parsefunc		g_parsejump[] = {
	{ "R", &parse_resolution },
	{ "A", &parse_ambient },
	{ "c", &parse_camera },
	{ "l", &parse_light },
	{ "sp", &parse_sphere },
	{ "pl", &parse_plane },
	{ "sq", &parse_square },
	{ "cy", &parse_cylinder },
	{ "tr", &parse_triangle },
	{ "ds", &parse_disk },
	{ NULL, NULL },
};

#endif
