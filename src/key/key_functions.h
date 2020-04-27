/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_functions.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:27:46 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 17:13:08 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_FUNCTIONS_H
# define KEY_FUNCTIONS_H

# include <minirt.h>
# include <key_codes.h>

typedef struct	s_keyfunc {
	int		key;
	void	(*func)(int, t_info *);
}				t_keyfunc;

void	key_move(int keycode, t_info *info);
void	key_rotate(int keycode, t_info *info);
void	key_exit(int keycode, t_info *info);
void	key_cam_cycle(int keycode, t_info *info);
void	key_resize(int keycode, t_info *info);
void	key_resize_cylinder(int keycode, t_info *info);

t_keyfunc	g_keyjump[] = {
	{ KEY_SPACE, &key_exit },
	{ KEY_ESC, &key_exit },
	{ KEY_Q, &key_cam_cycle },
	{ KEY_E, &key_cam_cycle },
	{ KEY_PLUS, &key_resize },
	{ KEY_MINUS, &key_resize },
	{ KEY_PGUP, &key_resize_cylinder },
	{ KEY_PGDN, &key_resize_cylinder },
	{ KEY_MOVE_RIGHT, &key_move },
	{ KEY_MOVE_LEFT, &key_move },
	{ KEY_MOVE_UP, &key_move },
	{ KEY_MOVE_DOWN, &key_move },
	{ KEY_MOVE_FORWARD, &key_move },
	{ KEY_MOVE_BACK, &key_move },
	{ KEY_ROT_UP_PLUS, &key_rotate },
	{ KEY_ROT_UP_MINUS, &key_rotate },
	{ KEY_ROT_RIGHT_PLUS, &key_rotate },
	{ KEY_ROT_RIGHT_MINUS, &key_rotate },
	{ KEY_ROT_FORWARD_PLUS, &key_rotate },
	{ KEY_ROT_FORWARD_MINUS, &key_rotate },
	{ 0, NULL },
};

#endif
