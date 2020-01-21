# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 15:41:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/01/21 22:21:52 by abe              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT
SRCS			=	gnl/get_next_line\
					gnl/get_next_line_utils\
					liblist/lst_foreach\
					liblist/lst_new\
					liblist/lst_new_back\
					error/error\
					hooks/frame\
					hooks/key\
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
					helpers/tocolor\
					math/vec_normalize\
					math/vec_add\
					math/vec_len\
					math/vec_dist\
					math/vec_multiply\
					math/ray_calc_dir\
					math/dist_line_point\
					math/col_multiply\
					renderer/get_pixel\
					renderer/ray_cast\
					renderer/obj_dist\
					renderer/obj_dist_sphere\
					renderer/get_frame\
					init_mlx

TESTS			=	math

CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

TEST_CFILES		=	$(TESTS:%=src/tests/%.c)
TEST_OFILES		=	$(TESTS:%=src/tests/%.o)

INCLUDES		=	-I include -I src/libft -I src/gnl -I src/liblist

LIBS			=

FLAGS			=	-Wall -Werror -Wextra -DNOLIST -O3

# OS detection for libs and headers
UNAME_S			:=	$(shell uname -s)

ifeq ($(UNAME_S),Linux)
LIBS			+=	-Llib/mlx -lmlx -lm -lX11 -lXext
INCLUDES		+=	-I lib/mlx/X11
FLAGS			+=	-DLINUX
endif

ifeq ($(UNAME_S),Darwin)
INCLUDES		+=	-I lib/mlx
endif

all: $(NAME)

ifeq ($(UNAME_S),Linux)

lib/mlx/libmlx.a:
	@echo "Making mlx"
	make -C lib/mlx
	@cp lib/mlx/X11/libmlx.a lib/mlx/

$(NAME): lib/mlx/libmlx.a $(OFILES) src/main.o
	@echo "Linking executable"
	@gcc $(OFILES) $(FLAGS) $(LIBS) -o $(NAME) -g src/main.o lib/mlx/libmlx.a
	@echo "Done"

test: lib/mlx/libmlx.a $(OFILES) $(TEST_OFILES)
	@echo "Linking executable"
	@gcc $(OFILES) $(FLAGS) $(LIBS) -o test -g $(TEST_OFILES)
	@echo "Done"

endif

ifeq ($(UNAME_S),Darwin)

lib/mlx/libmlx.dylib:
	@echo "Making mlx"
	make -C lib/mlx
	
$(NAME): lib/mlx/libmlx.dylib $(OFILES) src/main.o
	@echo "Linking executable"
	@gcc $(OFILES) $(FLAGS) $(LIBS) -o $(NAME) -g lib/mlx/libmlx.dylib src/main.o
	@echo "Copying dylib"
	@cp lib/mlx/libmlx.dylib .
	@echo "Done"

test: lib/mlx/libmlx.dylib $(OFILES) $(TEST_OFILES)
	@echo "Linking executable"
	@gcc $(OFILES) $(FLAGS) $(LIBS) -o test -g lib/mlx/libmlx.dylib $(TEST_OFILES)
	@echo "Done"

endif


%.o: %.c
	@echo "Compiling: $<"
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES) $(LIBS) -g

clean: _clean
	@echo "Cleaning..."

fclean: _clean
	@echo "Cleaning..."
	@rm -f $(NAME)

_clean:
	@rm -f $(OFILES)

re: fclean all
