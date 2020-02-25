/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:45:44 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/25 15:54:45 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdint.h>
# include <liblist.h>
# include <stdbool.h>

# define WINDOW_TITLE "miniRT"
# define FILE_NAME "scene.bmp"
# define MOVE_SPEED 1

# define RESIZE_SPEED 1.2

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
	double r;
	double g;
	double b;
}				t_color;

typedef struct	s_mlximg {
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_mlximg;

typedef struct	s_mlxinfo {
	void		*mlx;
	void		*mlx_win;
	t_mlximg	img;
}				t_mlxinfo;

typedef struct	s_mapinfo {
	t_vec2i		res;
	double		ambient_ratio;
	t_color		ambient_color;
	t_vec3f		cam_pos;
	t_vec3f		cam_orientation;
	uint8_t		cam_fov;
	t_vec3f		light_pos;
	double		light_brightness;
	t_color		light_color;
	bool		did_resolution;
	bool		did_ambient;
	bool		do_save;
	bool		rendered;
	uint32_t	tot_pixels;
}				t_mapinfo;

typedef enum	e_object_type {
	SP,
	PL,
	SQ,
	CY,
	TR,
	DS,
}				t_object_type;

typedef struct	s_object	t_object;

struct 			s_object {
	t_object_type	type;
	t_color			color;
	t_vec3f			location;
	double			size;
	double			height;
	t_vec3f			orientation;
	t_vec3f			points[3];
	t_object		*parent;
};

typedef struct	s_rayres {
	double		dist;
	t_vec3f		p;
	t_color		color;
	t_object	*obj;
}				t_rayres;

typedef struct	s_camera {
	t_vec3f	location;
	t_vec3f	orientation;
	uint8_t	fov;
}				t_camera;

typedef struct	s_light {
	t_vec3f	location;
	double	brightness;
	t_color	color;
}				t_light;

typedef struct	s_lightres {
	double	factor;
	t_light	*light;
}				t_lightres;

typedef struct	s_info {
	t_mapinfo	mapinfo;
	t_list		*objects;
	t_list		*cameras;
	t_list		*lights;
	t_mlxinfo	mlx_info;
	t_camera	*current_cam;
	t_object	*selected;
}				t_info;

typedef struct	s_thread_info {
	t_info			*info;
	uint32_t		start;
	t_color			*buf;
}				t_thread_info;

/*
**	Errors
*/

void			print_error(char *message, t_info *info);
void			print_error_free(char *message, t_info *info, void *to_free,
					void (*free_func)(void *));
void			print_error_free_words(char *message, t_info *info,
		char **words);
void			exit_clean(t_info *info);

/*
**	Helpers
*/

void			free_string_arr(char **array);
size_t			arrlen(char **array);
bool			isdigit_string(char *string);
double			parse_double(char *str);
t_vec3f			parse_vec3f(char *str, t_info *info);
t_color			parse_color(char *str, t_info *info);
bool			check_normalized(t_vec3f vec);
int				to_color(t_color color);
t_rayres		rayres_inf(void);
t_rayres		rayres_new(t_object *obj, t_vec3f p, t_color color);
t_rayres		rayres_new_dist(t_object *obj, t_vec3f p, t_color color, double dist);
t_ray			ray_new(t_vec3f origin, t_vec3f direction);
bool			float_compare(double a, double b);
uint32_t		min(uint32_t a, uint32_t b);
uint32_t		max(uint32_t a, uint32_t b);
bool			triangle_inside(t_object *tr, t_vec3f tr_normal, t_vec3f p);
t_object		*empty_object(t_info *info);
t_object		*empty_object_type(t_info *info, t_object_type type);
t_vec2i			pixel_new(int x, int y);

/*
**	Maths
*/

t_vec3f			vec_normalize(t_vec3f vec);
void			ray_calc_dir(t_ray *ray, t_vec3f cam);
t_vec3f			vec_new(double x, double y, double z);
double			vec_len(t_vec3f vec);
double			vec_dist(t_vec3f vec1, t_vec3f vec2);
t_vec3f			vec_add(t_vec3f vec1, t_vec3f vec2);
t_vec3f			vec_sub(t_vec3f vec1, t_vec3f vec2);
t_vec3f			vec_multiply(t_vec3f vec, double factor);
double			vec_dotp(t_vec3f vec1, t_vec3f vec2);
double			vec_angle(t_vec3f vec1, t_vec3f vec2);
t_vec3f			vec_from_to(t_vec3f from, t_vec3f to);
t_vec3f			vec_crossp(t_vec3f a, t_vec3f b);
t_vec3f			vec_rot_x(t_vec3f vec, double rad);
t_vec3f			vec_rot_y(t_vec3f vec, double rad);
t_vec3f			vec_rot_z(t_vec3f vec, double rad);
bool			point_line_closest(t_ray ray, t_vec3f c, t_vec3f *res);

/*
**	Colors
*/

t_color			col_new(float r, float g, float b);
t_color			col_multiply(t_color color, double factor);
t_color			col_mix(t_color col1, t_color col2);
t_color			col_mix_light(t_color col, t_color amb);
t_color			col_add_light(t_color a, t_color b);

/*
**	Structure functions
*/

void			parse_input(char *filename, t_info *info);
bool			init_mlx(t_info *info);
void			save_bmp(t_info *info);

/*
**	Hooks
*/

int				hook_frame(t_info *info);
int				hook_key(int keycode, t_info *info);
int				hook_mouse(int button, int x, int y, t_info *info);

/*
**	Renderer
*/

t_color			get_pixel(t_vec2i pixel, t_info *info);
t_rayres		obj_dist(t_object *obj, t_ray ray, t_info *info);
t_color			ray_cast(t_info *info, t_ray ray);
t_color			ray_cast_all_lights(t_info *info, t_rayres rayres, t_ray ray);
bool			ifo_cam(t_vec3f p, t_camera *cam);
t_vec3f			normal(t_rayres rayres, t_info *info);
bool			intersect(t_object *obj, t_ray ray, t_info *info);
t_vec3f			look_at(t_camera *cam, t_vec3f ray_origin);
t_ray			generate_ray(t_vec2i pixel, t_info *info);
void			resize(t_object *obj, bool increase, t_info *info);

t_color			*get_frame(t_info *info);
void			*renderer_thread(void *param);
t_thread_info	*thread_info_new(t_info *info, t_color *buf, uint32_t start);

/*
**	Free functions
*/

void			free_list(t_list *to_free, void (*free_func)(void *));
void			free_info(t_info *info);

/*
**	Children
*/

void			find_children(t_object *ob, t_object **to_store, t_info *info);
void			children_square(t_object *sq, t_info *info);
void			children_square_update(t_object *sq, t_info *info);
void			children_cylinder(t_object *cy, t_info *info);
void			children_cylinder_update(t_object *cy, t_info *info);

void			key(int keycode, t_info *info);

/*
**	Mouse
*/

void			select_object(t_vec2i pixel, t_info *info);

#endif
