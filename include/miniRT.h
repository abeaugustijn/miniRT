/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:45:44 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/24 11:57:44 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdint.h>
# include <liblist.h>
# include <stdbool.h>

# define WINDOW_TITLE "miniRT"
# define MOVE_SPEED 1

typedef struct	s_vec3f {
	double	x;
	double	y;
	double	z;
}				t_vec3f;

typedef struct	s_vec2f {
	double	x;
	double	y;
}				t_vec2f;

typedef struct	s_vec2i {
	uint16_t	x;
	uint16_t	y;
}				t_vec2i;

typedef struct	s_ray {
	t_vec3f	origin;
	t_vec3f direction;
}				t_ray;

typedef struct	s_color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
}				t_color;

typedef struct	s_mlxinfo {
	void	*mlx;
	void	*mlx_win;
}				t_mlxinfo;

typedef struct	s_mapinfo {
	t_vec2i		res;
	double		ambient_ratio;
	t_color		ambient_color;
	bool		did_resolution;
	bool		did_ambient;
	bool		do_save;
	bool		rendered;
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
	t_vec3f			location;
	double			size;
	double			height;
	t_vec3f			orientation;
	t_vec3f			points[3];
}				t_object;

typedef struct	s_camera {
	t_vec3f	location;
	t_vec3f	orientation;
	uint8_t	fov;
}				t_camera;

typedef struct	s_light {
	t_vec3f	location;
	float	brightness;
	t_color	color;
}				t_light;

typedef struct	s_info {
	t_mapinfo	mapinfo;
	t_list		*objects;
	t_list		*cameras;
	t_list		*lights;
	t_mlxinfo	mlx_info;
	t_camera	*current_cam;
}				t_info;

/*
**	Errors
*/

void			print_error(char *message);
void			print_error_free(char *message, void *to_free);
void			print_error_free_list(char *message, t_list *to_free);

/*
**	Helpers
*/

void			free_string_arr(char **array);
size_t			arrlen(char **array);
bool			isdigit_string(char *string);
float			parse_double(char *str);
t_vec3f			parse_vec3f(char *str);
t_color			parse_color(char *str);
bool			check_normalized(t_vec3f vec);
int				to_color(t_color color);

/*
**	Maths
*/

t_vec3f			vec3f_normalize(t_vec3f vec);
void			ray_calc_dir(t_ray *ray, t_vec3f cam);
double			vec_len(t_vec3f vec);
double			vec_dist(t_vec3f vec1, t_vec3f vec2);
t_vec3f			vec_add(t_vec3f vec1, t_vec3f vec2);
t_vec3f			vec_multiply(t_vec3f vec, double factor);
bool			point_line_closest(t_ray ray, t_vec3f c, t_vec3f *res);

/*
**	Colors
*/

t_color			col_new(uint8_t r, uint8_t g, uint8_t b);
t_color			col_multiply(t_color color, double factor);
t_color			col_mix(t_color col1, t_color col2);
t_color			col_mix_ambient(t_color col, t_color amb);

/*
**	Structure functions
*/

void			parse_input(char *filename, t_info *info);
bool			init_mlx(t_mlxinfo *mlx_info, t_info *info);

/*
**	Hooks
*/

int				hook_frame(t_info *info);
int				hook_key(int keycode, t_info *info);

/*
**	Renderer
*/

t_color			get_pixel(t_vec2i pixel, t_info *info);
double			obj_dist(t_object *obj, t_ray ray, t_color *color, t_info *info);
double			obj_dist_sphere(t_object *sp, t_ray ray, t_color *color, t_info *info);
t_color			ray_cast(t_info *info, t_ray ray);
t_color			*get_frame(t_info *info);

#endif
