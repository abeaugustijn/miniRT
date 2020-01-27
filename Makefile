# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 15:41:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/01/27 09:34:26 by abe              ###   ########.fr        #
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
					helpers/free_string_arr\
					helpers/arrlen\
					helpers/isdigit_string\
					helpers/parse_float\
					helpers/parse_vec3f\
					helpers/parse_color\
					helpers/check_normalized\
					helpers/tocolor\
					vec/vec_normalize\
					vec/vec_add\
					vec/vec_len\
					vec/vec_dist\
					vec/vec_multiply\
					math/ray_calc_dir\
					math/dist_line_point\
					col/col_multiply\
					col/col_new\
					col/col_mix\
					col/col_mix_ambient\
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

INCLUDES		=	-I include\
					-I lib/libft\
					-I lib/libgnl\
					-I lib/liblist

LIB_SRCS		=	libft\
					liblist\
					libmlx\
					libgnl

LIB_DIRS		=	$(LIB_SRCS:%=lib/%)

LIB_AFILES		=	$(LIB_SRCS:%=lib/%/%.a)

LIBS			=	-L lib/libft -lft\
					-L lib/liblist -llist\
					-L lib/libgnl -lgnl

FLAGS			=	-Wall -Werror -Wextra -DNOLIST -O3

# OS detection for libs and headers
UNAME_S			:=	$(shell uname -s)

ifeq ($(UNAME_S),Linux)
LIBS			+=	-Llib/libmlx -lmlx -lm -lX11 -lXext
INCLUDES		+=	-I lib/libmlx/X11
FLAGS			+=	-DLINUX
endif

ifeq ($(UNAME_S),Darwin)
INCLUDES		+=	-I lib/mlx
endif

all: $(NAME)


#LINUX

ifeq ($(UNAME_S),Linux)

lib/mlx/libmlx.a:
	@echo "Making mlx"
	make -C lib/libmlx
	cp -f lib/libmlx/X11/libmlx.a lib/libmlx/

$(NAME): $(LIB_DIRS) $(OFILES) src/main.o
	@echo "Linking executable"
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o $(NAME) -g src/main.o lib/libmlx/libmlx.a
	@echo "Done"

test: $(LIB_DIRS) $(OFILES) $(TEST_OFILES)
	@echo "Linking executable"
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o test -g $(TEST_OFILES)
	@echo "Done"

endif


# MACOS

ifeq ($(UNAME_S),Darwin)

lib/mlx/libmlx.dylib:
	@echo "Making mlx"
	make -C lib/mlx
	
$(NAME): lib/mlx/libmlx.dylib $(OFILES) src/main.o
	@echo "Linking executable"
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o $(NAME) -g lib/mlx/libmlx.dylib src/main.o
	@echo "Copying dylib"
	cp lib/mlx/libmlx.dylib .
	@echo "Done"

test: lib/mlx/libmlx.dylib $(OFILES) $(TEST_OFILES)
	@echo "Linking executable"
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o test -g lib/mlx/libmlx.dylib $(TEST_OFILES)
	@echo "Done"

endif


%.o: %.c
	@echo "Compiling: $<"
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES) $(LIBS) -g

lib/%/%.a: lib/%
	@echo "Making lib $@"
	make -C $<

clean: _clean
	@echo "Cleaning..."

fclean: _clean
	@echo "Cleaning..."
	@rm -f $(NAME)

_clean:
	@rm -f $(OFILES)

re: fclean all
