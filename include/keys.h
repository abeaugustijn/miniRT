/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:10:21 by abe               #+#    #+#             */
/*   Updated: 2020/02/11 17:00:33 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H

# ifdef LINUX
#  define KEY_SPACE 32
#  define KEY_Q 113
#  define KEY_H 104
#  define KEY_J 106
#  define KEY_K 107
#  define KEY_L 108
#  define KEY_UP 65362
#  define KEY_DOWN 65364
# else
#  define KEY_SPACE 49
#  define KEY_Q 12
#  define KEY_H 4
#  define KEY_J 38
#  define KEY_K 40
#  define KEY_L 37
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# endif

#endif
