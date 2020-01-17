# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 15:41:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/01/17 11:59:16 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT
SRCS			=	gnl/get_next_line\
					gnl/get_next_line_utils\
					liblist/lst_foreach\
					liblist/lst_new\
					liblist/lst_new_back\
					error/error\
					parser/parser\
					parser/parse_resolution\
					parser/parse_ambient\
					parser/parse_camera\
					parser/parse_light\
					parser/parse_sphere\
					parser/parse_plane\
					parser/parse_square\
					parser/parse_cylinder\
					parser/parse_triangle\
					libft/ft_putstr_fd\
					libft/ft_strlen\
					libft/ft_memset\
					libft/ft_bzero\
					libft/ft_split\
					libft/ft_atoi\
					libft/ft_strcmp\
					libft/ft_isdigit\
					helpers/free_string_arr\
					helpers/arrlen\
					helpers/isdigit_string\
					helpers/parse_float\
					helpers/parse_vec3f\
					helpers/parse_color\
					helpers/check_normalized\
					main

CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

INCLUDES		=	-I include -I src/libft -I src/gnl -I src/liblist -I lib/mlx

#LIBS			=	-L./lib/mlx -lmlx

# OS detection for libs
UNAME_S			:=	$(shell uname -s)

ifeq ($(UNAME_S),Linux)
LIBS			+=	-lm
endif

FLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

lib/mlx/libmlx.a:
	@echo "Making mlx"
	make -C lib/mlx

$(NAME): lib/mlx/libmlx.a $(OFILES)
	@echo "Linking executable"
	@gcc $(OFILES) $(FLAGS) $(LIBS) -o $(NAME) -g
	@echo "Done"

%.o: %.c
	@echo "Compiling: $<"
	@gcc -o $@ -c $< $(FLAGS) $(INCLUDES) $(LIBS) -g

clean: _clean
	@echo "Cleaning..."

fclean: _clean
	@echo "Cleaning..."
	@rm -f $(NAME)

_clean:
	@rm -f $(OFILES)

re: fclean all
