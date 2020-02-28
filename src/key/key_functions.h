/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:27:46 by aaugusti          #+#    #+#             */
/*   Updated: 2020/02/28 15:38:26 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_FUNCTIONS_H
# define KEY_FUNCTIONS_H

# include <miniRT.h>
# include <key_codes.h>

typedef struct	s_keyfunc {
	int		key;
	void	(*func)(int, t_info *);
}				t_keyfunc;

void	key_move_cam(int keycode, t_info *info);
void	key_rot_cam(int keycode, t_info *info);
void	key_exit(int keycode, t_info *info);
void	key_cam_cycle(int keycode, t_info *info);
void	key_resize(int keycode, t_info *info);
void	key_resize_cylinder(int keycode, t_info *info);

t_keyfunc	g_keyjump[] = {
	{ KEY_H, &key_move_cam },
	{ KEY_J, &key_move_cam },
	{ KEY_K, &key_move_cam },
	{ KEY_L, &key_move_cam },
	{ KEY_UP, &key_move_cam },
	{ KEY_DOWN, &key_move_cam },
	{ KEY_LEFT, &key_rot_cam },
	{ KEY_RIGHT, &key_rot_cam },
	{ KEY_SPACE, &key_exit },
	{ KEY_Q, &key_exit },
	{ KEY_ESC, &key_exit },
	{ KEY_A, &key_cam_cycle },
	{ KEY_D, &key_cam_cycle },
	{ KEY_PLUS, &key_resize },
	{ KEY_MINUS, &key_resize },
	{ KEY_PGUP, &key_resize_cylinder },
	{ KEY_PGDN, &key_resize_cylinder },
	{ 0, NULL },
};

#endif
