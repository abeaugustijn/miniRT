/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 20:34:10 by abe           #+#   #+#                  */
/*   Updated: 2020/03/20 14:15:20 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSER_H
# define PARSER_H
# include <minirt.h>

/*
**	Parse function per line
*/

void			parse_ambient(char **words, t_info *info);
void			parse_camera(char **words, t_info *info);
void			parse_cylinder(char **words, t_info *info);
void			parse_disk(char **words, t_info *info);
void			parse_light(char **words, t_info *info);
void			parse_plane(char **words, t_info *info);
void			parse_resolution(char **words, t_info *info);
void			parse_sphere(char **words, t_info *info);
void			parse_square(char **words, t_info *info);
void			parse_triangle(char **words, t_info *info);

/*
**	Other functions
*/

bool			parse_check_filename(char *filename);
double			parse_double(char *str);
size_t			parse_arrlen(char **array);
t_color			parse_color(char *str, t_info *info);
t_vec3f			parse_vec3f(char *str, t_info *info);
void			parse_convert_vlas(t_info *info);
void			parse_init_vlas(t_info *info);

/*
**	Struct to store the pointer to the functions and the idntifier which comes
**	with it.
*/

typedef struct	s_parsefunc {
	char	*identifier;
	void	(*func)(char **, t_info *);
}				t_parsefunc;

#endif
