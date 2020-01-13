/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:45:44 by aaugusti          #+#    #+#             */
/*   Updated: 2020/01/13 15:59:22 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdint.h>

typedef struct	s_vec3f {
	float	x;
	float	y;
	float	z;
}				t_vec3f;

typedef struct	s_mapinfo {
	uint8_t	res_x;
	uint8_t	res_y;
	float	ambient_ratio;
	uint8_t	ambient_color;
	t_vec3f	cam_pos;
	t_vec3f	cam_orientation;
	uint8_t	cam_fov;
	t_vec3f	light_pos;
	float	light_brightness;
	uint8_t	light_color;
}				t_mapinfo;

typedef enum	e_object_type {
	SP
}				t_object_type;

typedef struct 	s_object {
	t_object_type	type;
	t_vec3f			pos;
	float			diameter;
	uint8_t			color;
}				t_object;

#endif
