# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 15:41:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/03/17 10:46:34 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT
SRCS			=	cam/cam_update\
					children/children_cylinder\
					children/children_square\
					children/find_children\
					col/col_add_light\
					col/col_mix\
					col/col_mix_light\
					col/col_multiply\
					col/col_new\
					debug/print_vec3\
					error/error\
					free/free_info\
					free/free_string_arr\
					get_frame/get_frame\
					helpers/arrlen\
					helpers/empty_object\
					helpers/float_compare\
					helpers/isdigit_string\
					helpers/parse_color\
					helpers/parse_double\
					helpers/parse_vec3f\
					helpers/pixel_new\
					helpers/ray_new\
					helpers/ray_point\
					helpers/rayres_inf\
					helpers/rayres_new\
					helpers/tocolor\
					helpers/triangle_inside\
					hooks/hook_frame\
					hooks/hook_key\
					hooks/hook_mouse\
					init_mlx\
					intersect/intersect\
					intersect/intersect_cylinder\
					intersect/intersect_disk\
					intersect/intersect_plane\
					intersect/intersect_sphere\
					intersect/intersect_square\
					intersect/intersect_triangle\
					key/key_cam_cycle\
					key/key_exit\
					key/key_functions\
					key/key_move\
					key/key_resize\
					key/key_resize_cylinder\
					key/key_rotate\
					math/points_line_closest\
					mouse/select_object\
					move/move_cam\
					move/move_cylinder\
					move/move_disk\
					move/move_get_cam_dir\
					move/move_obj\
					move/move_plane\
					move/move_sphere\
					move/move_square\
					move/move_triangle\
					normal/normal\
					normal/normal_cylinder\
					normal/normal_disk\
					normal/normal_plane\
					normal/normal_sphere\
					normal/normal_square\
					normal/normal_triangle\
					parser/parse_ambient\
					parser/parse_camera\
					parser/parse_cylinder\
					parser/parse_disk\
					parser/parse_light\
					parser/parse_plane\
					parser/parse_resolution\
					parser/parse_sphere\
					parser/parse_square\
					parser/parse_triangle\
					parser/parser\
					quat/quat_inverse\
					quat/quat_len\
					quat/quat_multiply\
					quat/quat_new\
					quat/quat_normalize\
					quat/quat_rot\
					quat/quat_rot_local\
					quat/quat_to_vec3\
					renderer/fix_dir_vecs\
					renderer/fix_normal\
					renderer/generate_ray\
					renderer/get_dir_vecs\
					renderer/get_pixel\
					renderer/look_at\
					renderer/ray_cast\
					renderer/ray_cast_light\
					resize/resize\
					resize/resize_cylinder\
					resize/resize_sphere\
					resize/resize_square\
					rotate/rotate_cam\
					rotate/rotate_cylinder\
					rotate/rotate_disk\
					rotate/rotate_get_dir\
					rotate/rotate_obj\
					rotate/rotate_plane\
					rotate/rotate_square\
					save_bmp\
					update/update\
					update/update_cylinder\
					update/update_dir_vecs\
					update/update_disk\
					update/update_plane\
					update/update_square\
					vec/vec_add\
					vec/vec_angle\
					vec/vec_compare\
					vec/vec_crossp\
					vec/vec_dist\
					vec/vec_dotp\
					vec/vec_from_to\
					vec/vec_is_normal\
					vec/vec_len\
					vec/vec_multiply\
					vec/vec_new\
					vec/vec_normalize\
					vec/vec_rot\
					vec/vec_sub\

BONUS_SRCS		=	get_frame/renderer_thread\
					get_frame/thread_info_new\

#These are files that need to be recompiled when the bonus is made
BONUS_RECOMP	=	main\
					get_frame/get_frame\

TESTS			=	math

CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

BONUS_CFILES	=	$(BONUS_SRCS:%=src/%.c)
BONUS_OFILES	=	$(BONUS_SRCS:%=src/%.o)

BONUS_RECOMP_O	=	$(BONUS_RECOMP:%=src/%.o)

TEST_CFILES		=	$(TESTS:%=src/tests/%.c)
TEST_OFILES		=	$(TESTS:%=src/tests/%.o)

INCLUDES		=	-I include\
					-I lib/libft\
					-I lib/libgnl\
					-I lib/libvla\
					-I lib/libftprintf\

LIB_SRCS		=	lib/libft/libft.a\
					lib/libgnl/libgnl.a\
					lib/libvla/libvla.a\
					lib/libftprintf/libftprintf.a\

FLAGS			=	-Wall -Werror -Wextra -DNOLIST -O0 --std=c11

# OS detection for libs and headers
UNAME_S			:=	$(shell uname -s)
LAST_BONUS		:=	$(shell ls bonus 2> /dev/null)

ifeq ($(UNAME_S),Linux)
LIBS			+=	-Llib/libmlx -lmlx -lm -lX11 -lXext -lpthread
INCLUDES		+=	-I lib/libmlx/X11
FLAGS			+=	-DLINUX
LIB_SRCS		+=	lib/libmlx/libmlx.a
endif

ifeq ($(UNAME_S),Darwin)
INCLUDES		+=	-I lib/libmlx
endif

all: $(NAME)

#Used to add the 'BONUS' flag to compiling all sources
set_bonus:
	$(eval FLAGS += -DBONUS)

clean_bonus:
	rm -f $(BONUS_RECOMP_O)

.PHONY: set_bonus clean_bonus

#LINUX

ifeq ($(UNAME_S),Linux)

FLAGS		+= -DNCORES=$(shell getconf _NPROCESSORS_ONLN)

lib/libmlx/libmlx.a:
	make -C lib/libmlx
	cp lib/libmlx/X11/libmlx.a lib/libmlx

$(NAME): clean_bonus $(LIB_SRCS) $(OFILES) src/main.o
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o $(NAME) -g src/main.o $(LIB_SRCS)
	@rm -f bonus

bonus: set_bonus clean_bonus $(LIB_SRCS) $(OFILES) $(BONUS_OFILES) src/main.o
	$(CC) $(OFILES) $(BONUS_OFILES) $(FLAGS) $(LIBS) -o $(NAME) -g src/main.o\
		$(LIB_SRCS)
	@touch bonus

test: $(LIB_SRCS) $(OFILES) $(TEST_OFILES)
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o test -g $(TEST_OFILES) $(LIB_SRCS)

endif


# MACOS

ifeq ($(UNAME_S),Darwin)

FLAGS		+= -DNCORES=$(shell sysctl -n hw.ncpu)

lib/libmlx/libmlx.dylib:
	make -C lib/libmlx
	cp lib/libmlx/libmlx.dylib .

$(NAME): clean_bonus $(LIB_SRCS) $(OFILES) src/main.o lib/libmlx/libmlx.dylib
	$(CC) $(OFILES) $(FLAGS) $(LIBS) -o $(NAME) $(LIB_SRCS) -g src/main.o libmlx.dylib
	cp lib/libmlx/libmlx.dylib .
	@rm -f bonus

bonus: set_bonus clean_bonus $(LIB_SRCS) $(OFILES) $(BONUS_OFILES) src/main.o lib/libmlx/libmlx.dylib
	$(CC) $(OFILES) $(BONUS_OFILES) $(FLAGS) $(LIBS) -o $(NAME) $(LIB_SRCS)\
		-g src/main.o libmlx.dylib
	cp lib/libmlx/libmlx.dylib .
	@touch bonus

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
	make fclean -C lib/libft
	make fclean -C lib/libgnl
	make fclean -C lib/libvla
	make fclean -C lib/libftprintf
	rm -f $(NAME)
	rm -f bonus

_clean:
	rm -f $(OFILES) $(BONUS_OFILES) src/main.o


re: fclean all
