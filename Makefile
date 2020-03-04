# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 15:41:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/03/04 16:19:12 by abe              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT
SRCS			=	error/error\
					hooks/hook_frame\
					hooks/hook_key\
					hooks/hook_mouse\
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
					parser/parse_disk\
					helpers/arrlen\
					helpers/isdigit_string\
					helpers/parse_double\
					helpers/parse_vec3f\
					helpers/parse_color\
					helpers/tocolor\
					helpers/rayres_inf\
					helpers/rayres_new\
					helpers/ray_new\
					helpers/ray_point\
					helpers/float_compare\
					helpers/triangle_inside\
					helpers/empty_object\
					helpers/pixel_new\
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
					vec/vec_crossp\
					vec/vec_rot\
					vec/vec_is_normal\
					vec/vec_compare\
					math/points_line_closest\
					col/col_multiply\
					col/col_new\
					col/col_mix\
					col/col_mix_light\
					col/col_add_light\
					renderer/generate_ray\
					renderer/get_pixel\
					renderer/ray_cast\
					renderer/ray_cast_light\
					renderer/look_at\
					renderer/fix_normal\
					obj_dist/obj_dist\
					obj_dist/obj_dist_sphere\
					obj_dist/obj_dist_plane\
					obj_dist/obj_dist_cylinder\
					obj_dist/obj_dist_triangle\
					obj_dist/obj_dist_disk\
					free/free_info\
					free/free_string_arr\
					normal/normal\
					normal/normal_sphere\
					normal/normal_plane\
					normal/normal_square\
					normal/normal_cylinder\
					normal/normal_triangle\
					normal/normal_disk\
					intersect/intersect\
					intersect/intersect_sphere\
					intersect/intersect_plane\
					intersect/intersect_cylinder\
					intersect/intersect_triangle\
					intersect/intersect_square\
					intersect/intersect_disk\
					resize/resize\
					resize/resize_sphere\
					resize/resize_square\
					resize/resize_cylinder\
					children/find_children\
					children/children_square\
					children/children_cylinder\
					key/key_functions\
					key/key_move_cam\
					key/key_rot_cam\
					key/key_exit\
					key/key_cam_cycle\
					key/key_resize\
					key/key_resize_cylinder\
					mouse/select_object\
					get_frame/get_frame\
					cam/cam_update\
					init_mlx\
					save_bmp\

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

LIB_SRCS		=	lib/libft/libft.a\
					lib/libgnl/libgnl.a\
					lib/libvla/libvla.a\

FLAGS			=	-Wall -Werror -Wextra -DNOLIST -O0

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

#Only clean the bonus files if the lastly linked executable was not bonus
ifeq ($(LAST_BONUS),bonus)
clean_bonus:
else
clean_bonus:
	rm -f $(BONUS_RECOMP_O)
endif

.PHONY: set_bonus clean_bonus

#LINUX

ifeq ($(UNAME_S),Linux)

FLAGS		+= -DNCORES=$(shell getconf _NPROCESSORS_ONLN)

lib/libmlx/libmlx.a:
	make -C lib/libmlx
	cp lib/libmlx/X11/libmlx.a lib/libmlx

$(NAME): $(LIB_SRCS) $(OFILES) src/main.o
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

$(NAME): $(LIB_SRCS) $(OFILES) src/main.o lib/libmlx/libmlx.dylib
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
	rm -f $(NAME)
	rm -f bonus

_clean:
	rm -f $(OFILES) $(BONUS_OFILES) src/main.o


re: fclean all
