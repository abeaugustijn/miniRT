/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:34:10 by abe               #+#    #+#             */
/*   Updated: 2020/01/14 22:11:03 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSE_FUNCTIONS_H
# define PARSE_FUNCTIONS_H
# include <miniRT.h>
# include <liblist.h>

void	parse_resolution(char **words, t_info *info);
void	parse_ambient(char **words, t_info *info);
void	parse_camera(char **words, t_info *info);
void	parse_light(char **words, t_info *info);
void	parse_sphere(char **words, t_info *info);
void	parse_plane(char **words, t_info *info);
void	parse_square(char **words, t_info *info);
void	parse_cylinder(char **words, t_info *info);
void	parse_triangle(char **words, t_info *info);

#endif
