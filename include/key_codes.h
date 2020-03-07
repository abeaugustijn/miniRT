/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:10:21 by abe               #+#    #+#             */
/*   Updated: 2020/03/07 15:30:31 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODES_H
# define KEY_CODES_H

# ifdef LINUX
#  define KEY_SPACE 32
#  define KEY_A ((int)'a')
#  define KEY_D ((int)'d')
#  define KEY_E ((int)'e')
#  define KEY_H ((int)'h')
#  define KEY_J ((int)'j')
#  define KEY_K ((int)'k')
#  define KEY_L ((int)'l')
#  define KEY_S ((int)'s')
#  define KEY_W ((int)'w')
#  define KEY_Q ((int)'q')
#  define KEY_UP (65362)
#  define KEY_DOWN (65364)
#  define KEY_LEFT (65361)
#  define KEY_RIGHT (65363)
#  define KEY_PLUS (61)
#  define KEY_MINUS (45)
#  define KEY_PGUP (65366)
#  define KEY_PGDN (65365)
#  define KEY_ESC (65307)
#  define KEY_NUM_1 (46)
#  define KEY_NUM_2 (47)
#  define KEY_NUM_3 (65506)
#  define KEY_NUM_4 (59)
#  define KEY_NUM_5 (39)
#  define KEY_NUM_6 (65293)
#  define KEY_NUM_7 (91)
#  define KEY_NUM_8 (93)
#  define KEY_NUM_9 (92)
#  define KEY_NUM_PLUS (69)
#  define KEY_NUM_MINUS (78)
# else
#  define KEY_SPACE (49)
#  define KEY_A (0)
#  define KEY_D (2)
#  define KEY_H (4)
#  define KEY_J (38)
#  define KEY_K (40)
#  define KEY_L (37)
#  define KEY_Q (12)
#  define KEY_UP (126)
#  define KEY_DOWN (125)
#  define KEY_LEFT (123)
#  define KEY_RIGHT (124)
#  define KEY_PLUS (24)
#  define KEY_MINUS (27)
#  define KEY_PGUP (116)
#  define KEY_PGDN (121)
#  define KEY_ESC (53)
#  define KEY_NUM_1 (83)
#  define KEY_NUM_2 (84)
#  define KEY_NUM_3 (85)
#  define KEY_NUM_4 (86)
#  define KEY_NUM_5 (87)
#  define KEY_NUM_6 (88)
#  define KEY_NUM_7 (89)
#  define KEY_NUM_8 (91)
#  define KEY_NUM_9 (92)
#  define KEY_NUM_PLUS (69)
#  define KEY_NUM_MINUS (78)
# endif

# define KEY_OBJ_RIGHT (KEY_NUM_6)
# define KEY_OBJ_LEFT (KEY_NUM_4)
# define KEY_OBJ_BACK (KEY_NUM_2)
# define KEY_OBJ_FORWARD (KEY_NUM_8)
# ifdef LINUX
#  define KEY_OBJ_UP (KEY_NUM_9)
#  define KEY_OBJ_DOWN (KEY_NUM_3)
# else
#  define KEY_OBJ_UP (KEY_NUM_PLUS)
#  define KEY_OBJ_DOWN (KEY_NUM_MINUS)
# endif

#endif
