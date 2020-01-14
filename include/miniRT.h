/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:45:44 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/14 22:29:01 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdint.h>
# include <liblist.h>
# include <stdbool.h>

typedef struct	s_vec3f {
	float	x;
	float	y;
	float	z;
}				t_vec3f;

typedef struct	s_color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
}				t_color;

typedef struct	s_mapinfo {
	int		res_x;
	int		res_y;
	float	ambient_ratio;
	t_color	ambient_color;
	t_vec3f	cam_pos;
	t_vec3f	cam_orientation;
	uint8_t	cam_fov;
	t_vec3f	light_pos;
	float	light_brightness;
	t_color	light_color;
}				t_mapinfo;

typedef enum	e_object_type {
	SP,
	PL,
	SQ,
	CY,
	TR
}				t_object_type;

typedef struct 	s_object {
	t_object_type	type;
	t_color			color;
	void			*object_data;
	t_vec3f			location;
}				t_object;

typedef struct	s_sphere {
	float	diameter;
}				t_sphere;

typedef struct	s_plane {
	t_vec3f	orientation;
}				t_plane;

typedef struct	s_square {
	t_vec3f	orientation;
	float	size;
}				t_square;

typedef struct	s_cylinder {
	t_vec3f	orientation;
	float	diameter;
	float	height;
}				t_cylinder;

typedef struct	s_triangle {
	t_vec3f	point1;
	t_vec3f	point2;
	t_vec3f	point3;
}				t_triangle;

typedef struct	s_info {
	t_mapinfo	mapinfo;
	t_list		*objects;
	t_list		*cameras;
	t_list		*lights;
}				t_info;

typedef struct	s_camera {
	t_vec3f	location;
	t_vec3f	orientation;
	uint8_t	fov;
}				t_camera;

/*
**	Parsing
*/

void			parse_input(char *filename, t_info *info);
void			print_error(char *message);

/*
**	Helpers
*/

void			free_string_arr(char **array);
size_t			arrlen(char **array);
bool			isdigit_string(char *string);
float			parse_float(char *str);
t_vec3f			parse_vec3f(char *str);
t_color			parse_color(char *str);
bool			check_normalized(t_vec3f vec);

#endif
