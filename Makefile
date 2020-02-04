# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 15:41:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/02/04 14:29:51 by abe              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT
SRCS			=	error/error\
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
					helpers/arrlen\
					helpers/isdigit_string\
					helpers/parse_double\
					helpers/parse_vec3f\
					helpers/parse_color\
					helpers/check_normalized\
					helpers/tocolor\
					helpers/rayres_inf\
					helpers/rayres_new\
					helpers/float_compare\
					vec/vec_new\
					vec/vec_normalize\
					vec/vec_angle\
					vec/vec_add\
					vec/vec_sub\
					vec/vec_len\
					vec/vec_dist\
					vec/vec_multiply\
					vec/vec_dotp\
					vec/vec_from_to\
					math/dist_line_point\
					col/col_multiply\
					col/col_new\
					col/col_mix\
					col/col_mix_light\
					renderer/get_pixel\
					renderer/ray_cast\
					renderer/ray_cast_light\
					renderer/obj_dist\
					renderer/obj_dist_sphere\
					renderer/obj_dist_plane\
					free/free_list\
					free/free_info\
					free/free_string_arr\
					normal/normal\
					normal/normal_sphere\
					normal/normal_plane\
					init_mlx

TESTS			=	math

CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

TEST_CFILES		=	$(TESTS:%=src/tests/%.c)
TEST_OFILES		=	$(TESTS:%=src/tests/%.o)

INCLUDES		=	-I include\
					-I lib/libft\
					-I lib/libgnl\
					-I lib/liblist

LIB_SRCS		=	lib/libft/libft.a\
					lib/liblist/liblist.a\
					lib/libgnl/libgnl.a

FLAGS			=	-Wall -Werror -Wextra -DNOLIST -O0

# OS detection for libs and headers
UNAME_S			:=	$(shell uname -s)

ifeq ($(UNAME_S),Linux)
LIBS			+=	-Llib/libmlx -lmlx -lm -lX11 -lXext
INCLUDES		+=	-I lib/libmlx/X11
FLAGS			+=	-DLINUX
LIB_SRCS		+=	lib/libmlx/libmlx.a
endif

ifeq ($(UNAME_S),Darwin)
INCLUDES		+=	-I lib/libmlx
endif

all: $(NAME)


#LINUX

ifeq ($(UNAME_S),Linux)

lib/libmlx/libmlx.a:
	make -C lib/libmlx

$(NAME): $(LIB_SRCS) $(OFILES) src/main.o
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o $(NAME) -g src/main.o $(LIB_SRCS)

test: $(LIB_SRCS) $(OFILES) $(TEST_OFILES)
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o test -g $(TEST_OFILES) $(LIB_SRCS)

endif


# MACOS

ifeq ($(UNAME_S),Darwin)

lib/libmlx/libmlx.dylib:
	make -C lib/libmlx
	cp lib/libmlx/libmlx.dylib .

$(NAME): $(LIB_SRCS) $(OFILES) src/main.o lib/libmlx/libmlx.dylib
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o $(NAME) $(LIB_SRCS) -g src/main.o libmlx.dylib
	cp lib/libmlx/libmlx.dylib .

test: $(LIB_SRCS) $(OFILES) $(TEST_OFILES)
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o test $(LIB_SRCS) -g  $(TEST_OFILES) libmlx.dylib

endif


%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES) $(LIBS) -g

%.a:
	make -C $(@D)

clean: _clean

fclean: _clean
	make clean -C lib/libmlx
	make fclean -C lib/liblist
	make fclean -C lib/libft
	make fclean -C lib/libgnl
	rm -f $(NAME)

_clean:
	rm -f $(OFILES)

re: fclean all
