/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 15:45:44 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/14 12:41:23 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <libvec.h>
# include <libvla.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef M_PI
#  define M_PI (3.141592653589793238)
# endif
# ifndef M_PI_2
#  define M_PI_2 (M_PI / 2)
# endif

# define WINDOW_TITLE "miniRT"
# define FILE_NAME "scene.bmp"

# define MOVE_SPEED (1.0)
# define LIGHT_FACTOR (100.0)
# define RESIZE_SPEED (1.2)
# ifndef EPSILON
#  define EPSILON (0.000001)
# endif

typedef struct	s_vec4f {
	double	w;
	double	x;
	double	y;
	double	z;
}				t_vec4f;

typedef struct	s_vec2i {
	uint16_t	x;
	uint16_t	y;
}				t_vec2i;

typedef struct	s_ray {
	t_vec3f	origin;
	t_vec3f direction;
}				t_ray;

typedef t_ray	t_line;

typedef struct	s_color {
	double r;
	double g;
	double b;
}				t_color;

typedef struct	s_mlximg {
	char		*addr;
	int			bpp;
	int			endian;
	int			line_length;
	void		*ptr;
}				t_mlximg;

typedef struct	s_mlxinfo {
	t_mlximg	img;
	void		*mlx;
	void		*mlx_win;
}				t_mlxinfo;

typedef struct	s_mapinfo {
	bool		did_ambient;
	bool		did_resolution;
	bool		do_save;
	bool		rendered;
	double		ambient_ratio;
	t_color		ambient_color;
	t_vec2i		res;
	uint32_t	tot_pixels;
}				t_mapinfo;

typedef enum	e_object_type {
	SP = 0,
	PL = 1,
	SQ = 2,
	CY = 3,
	TR = 4,
	DS = 5,
}				t_object_type;

typedef enum	e_move_dir {
	UP = 0,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 3,
	FORWARD = 4,
	BACK = 5,
}				t_move_dir;

typedef struct	s_dir_vecs {
	t_vec3f	forward;
	t_vec3f	right;
	t_vec3f	up;
}				t_dir_vecs;

typedef struct	s_object {
	bool			has_parent;
	double			height;
	double			size;
	size_t			parent_i;
	t_color			color;
	t_dir_vecs		dir_vecs;
	t_object_type	type;
	t_vec3f			location;
	t_vec3f			points[3];
}				t_object;

typedef struct	s_rayres {
	double		dist;
	t_object	*obj;
	t_vec3f		normal;
	t_vec3f		p;
}				t_rayres;

typedef struct	s_camera {
	t_dir_vecs	dir_vecs;
	t_vec3f		location;
	t_vec3f		orientation;
	uint8_t		fov;
}				t_camera;

typedef struct	s_light {
	double	brightness;
	t_color	color;
	t_vec3f	location;
}				t_light;

typedef struct	s_info {
	char			*current_line;
	size_t			current_cam_i;
	t_camera		*current_cam;
	t_mapinfo		mapinfo;
	t_mlxinfo		mlx_info;
	t_object		*selected;
	t_vla			cameras;
	t_vla			lights;
	t_vla			objects;
}				t_info;

typedef struct	s_thread_info {
	t_color			*buf;
	t_info			*info;
	uint32_t		start;
}				t_thread_info;

/*
**	Errors
*/

void			exit_clean(t_info *info);
void			print_error(char *message, t_info *info);
void			print_error_free(char *message, t_info *info, void *to_free,
					void (*free_func)(void *));
void			print_error_free_words(char *message, t_info *info,
					char **words);

/*
**	Helpers
*/

bool			float_compare(double a, double b);
int				to_color(t_color color);
t_object		empty_object(void);
t_object		empty_object_type(t_object_type type);
t_ray			ray_new(t_vec3f origin, t_vec3f direction);
t_rayres		rayres_inf(void);
t_rayres		rayres_new(t_object *obj, t_vec3f p, double dist,
					t_vec3f normal);
t_vec3f			ray_point(t_ray ray, double t);

/*
**	Maths
*/

void			points_line_closest(t_line line_a, t_line line_b,
					double *results);
void			rotate_relative(t_vec3f *forward, t_vec3f direction,
					double factor);
bool			triangle_inside(t_object *tr, t_vec3f tr_normal, t_vec3f p);

/*
**	Quaternians
*/

double			quat_len(t_vec4f quat);
t_vec3f			quat_to_vec3(t_vec4f quat);
t_vec4f			quat_inverse(t_vec4f quat);
t_vec4f			quat_multiply(t_vec4f a, t_vec4f b);
t_vec4f			quat_new(double w, double x, double y, double z);
t_vec4f			quat_normalize(t_vec4f quat);
t_vec4f			quat_rot(t_vec3f orientation, t_vec3f rot_dir, double angle);
t_vec4f			quat_rot_local(t_vec3f rot_dir, double angle);

/*
**	Colors
*/

t_color			col_add_light(t_color a, t_color b);
t_color			col_mix(t_color col1, t_color col2);
t_color			col_mix_light(t_color col, t_color amb);
t_color			col_multiply(t_color color, double factor);
t_color			col_new(float r, float g, float b);

/*
**	Structure functions
*/

bool			init_mlx(t_info *info);
void			parse_input(char *filename, t_info *info);
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

t_color			*get_frame(t_info *info);
t_color			get_pixel(t_vec2i pixel, t_info *info);
t_color			ray_cast(t_info *info, t_ray ray);
t_color			ray_cast_all_lights(t_info *info, t_rayres rayres, t_ray ray);
t_dir_vecs		fix_dir_vecs(t_vec3f cam_direction, t_dir_vecs dir_vecs);
t_dir_vecs		get_dir_vecs(t_vec3f cam_dir);
t_ray			generate_ray(t_vec2i pixel, t_info *info);
t_thread_info	*thread_info_new(t_info *info, t_color *buf, uint32_t start);
t_vec3f			fix_normal(t_vec3f ray_direction, t_vec3f normal);
t_vec3f			move_get_dir(t_move_dir move_dir, t_dir_vecs dir_vecs);
void			*renderer_thread(void *param);

/*
**	Camera
*/

t_vec3f			look_at(t_camera *cam, t_vec3f ray_origin);
void			cam_update(t_camera *cam);
void			cam_update_up(t_camera *cam);
void			cam_update_forward(t_camera *cam);
void			move_cam(int keycode, t_info *info);
void			move_obj(int keycode, t_info *info);
void			rotate_cam(int keycode, t_info *info);
void			rotate_obj(int keycode, t_info *info);

/*
**	Object functions
*/

double			intersect(t_object *obj, t_ray ray, t_vec3f *normal,
					t_info *info);
t_vec3f			normal(t_rayres rayres, t_ray ray, t_info *info);
void			resize(t_object *obj, bool increase, t_info *info);
void			rotate(t_object *obj, t_move_dir axis, t_info *info);
void			update(t_object *obj, t_info *info);

/*
**	Free functions
*/

void			free_info(t_info *info);
void			free_words(char **array);

/*
**	Children
*/

void			children_cylinder_gen(t_object *cy, t_info *info);
void			children_cylinder_update(t_object *cy, t_info *info);
void			children_square_gen(t_object *sq, t_info *info);
void			children_square_update(t_object *sq, t_info *info);
void			find_children(t_object *ob, t_object **to_store, t_info *info);

/*
**	I/O
*/

void			key(int keycode, t_info *info);
void			select_object(t_vec2i pixel, t_info *info);

#endif
