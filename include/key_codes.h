/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:10:21 by abe               #+#    #+#             */
/*   Updated: 2020/02/28 19:55:02 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODES_H
# define KEY_CODES_H

# ifdef LINUX
#  define KEY_SPACE 32
#  define KEY_A (int)'a'
#  define KEY_D (int)'d'
#  define KEY_H (int)'h'
#  define KEY_J (int)'j'
#  define KEY_K (int)'k'
#  define KEY_L (int)'l'
#  define KEY_Q (int)'q'
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_PLUS 61 
#  define KEY_MINUS 45
#  define KEY_PGUP 65366
#  define KEY_PGDN 65365
#  define KEY_ESC 53
# else
#  define KEY_SPACE 49
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_H 4
#  define KEY_J 38
#  define KEY_K 40
#  define KEY_L 37
#  define KEY_Q 12
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_PLUS 24
#  define KEY_MINUS 27
#  define KEY_PGUP 116
#  define KEY_PGDN 121
#  define KEY_ESC 53
# endif

#endif
