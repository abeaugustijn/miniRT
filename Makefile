# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/20 14:03:39 by aaugusti          #+#    #+#              #
#    Updated: 2020/04/14 15:06:14 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT

all: $(NAME)

# All source of the application
SRCS			=	cam/cam_update\
					children/children_cylinder\
					children/children_square\
					children/find_children\
					col/col_add_light\
					col/col_mix\
					col/col_mix_light\
					col/col_multiply\
					col/col_new\
					error/error\
					free/free_info\
					free/free_words\
					get_frame/get_frame\
					helpers/empty_object\
					helpers/float_compare\
					helpers/ray_new\
					helpers/ray_point\
					helpers/rayres_inf\
					helpers/rayres_new\
					helpers/tocolor\
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
					main\
					math/points_line_closest\
					math/rotate_relative\
					math/triangle_inside\
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
					parser/parse_convert_vlas\
					parser/parse_init_vlas\
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
					parser/parse_ambient\
					parser/parse_arrlen\
					parser/parse_camera\
					parser/parse_check_filename\
					parser/parse_color\
					parser/parse_cylinder\
					parser/parse_double\
					parser/parse_light\
					parser/parse_plane\
					parser/parse_resolution\
					parser/parse_sphere\
					parser/parse_square\
					parser/parse_triangle\
					parser/parse_vec3f\
					parser/parser\

# Sources which are just needed for the bonus part
BONUS_SRCS		=	get_frame/renderer_thread\
					get_frame/thread_info_new\
					parser/parse_disk\

# These are files that need to be recompiled when the bonus is made
BONUS_RECOMP	=	get_frame/get_frame\
					parser/parser\


CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

BONUS_CFILES	=	$(BONUS_SRCS:%=src/%.c)
BONUS_OFILES	=	$(BONUS_SRCS:%=src/%.o)

BONUS_RECOMP_O	=	$(BONUS_RECOMP:%=src/%.o)


# Paths to the headeres which are needed
INCLUDES		=	-I include\
					-I lib/libft\
					-I lib/libftprintf\
					-I lib/libgnl\
					-I lib/libvec\
					-I lib/libvla\

# The location of al libraries
LIB_SRCS		=	lib/libft/libft.a\
					lib/libftprintf/libftprintf.a\
					lib/libgnl/libgnl.a\
					lib/libvec/libvec.a\
					lib/libvla/libvla.a\

FLAGS			=	-Wall -Werror -Wextra -DNOLIST

# Ability to compile with maximum optimization
ifeq ($(FAST),1)
FLAGS			+= -Ofast
else
FLAGS			+= -O0
endif

# OS detection for libs and headers
UNAME_S			:=	$(shell uname -s)

ifeq ($(UNAME_S),Linux)
LIBS			+=	-Llib/libmlx -lmlx -lm -lX11 -lXext -lpthread
INCLUDES		+=	-I lib/libmlx/X11
FLAGS			+=	-DLINUX
LIB_SRCS		+=	lib/libmlx/libmlx.a
endif #Linux

ifeq ($(UNAME_S),Darwin)
INCLUDES		+=	-I lib/libmlx
LIB_SRCS		+= 	lib/libmlx/libmlx.dylib
DYLIB			+= libmlx.dylib
endif #Darwin


TARGETS			=	$(OFILES) $(LIB_SRCS)

ifeq ($(BONUS),1)
TARGETS			+=	$(BONUS_OFILES)
FLAGS			+=	-DBONUS
endif #Bonus

# This means that the build before this one was indeed bonus, so we need to
# recompile the bonus-specific files and remove the bonus file.
ifeq ($(shell ls bonus 2> /dev/null),bonus)
TARGETS_EXTRA	= clean_bonus
endif #Last was bonus

# Another case in which we need to recompile the bonus files. This is true when
# we build the bonus, but the previous build was not bonus.
ifeq ($(BONUS),1)
ifneq ($(shell ls bonus 2> /dev/null),bonus)
TARGETS_EXTRA	= clean_bonus
endif #Last was bonus
endif #Bonus 

clean_bonus:
	rm -f $(BONUS_RECOMP_O)
	rm -f bonus


# Two rules concerning the compilation of the MiniLibX. They differ on MacOS
# and Linux.
ifeq ($(UNAME_S), Linux)
lib/libmlx/libmlx.a:
	make -C lib/libmlx
	cp lib/libmlx/X11/libmlx.a lib/libmlx/libmlx.a
endif #Linux

ifeq ($(UNAME_S), Darwin)
lib/libmlx/libmlx.dylib:
	make -C lib/libmlx
	cp lib/libmlx/libmlx.dylib .
endif #Darwin


# This compile flag needs to be set when we compile with bonus, so the code
# knows how many cores are in the system.
ifeq ($(BONUS), 1)
ifeq ($(UNAME_S), Linux)
FLAGS			+=	-DNCORES=$(shell getconf _NPROCESSORS_ONLN)
endif #Linux
ifeq ($(UNAME_S), Darwin)
FLAGS			+=	-DNCORES=$(shell sysctl -n hw.ncpu)
endif #Darwin
endif #Bonus


$(NAME): $(TARGETS_EXTRA) $(TARGETS)
	$(CC) $(TARGETS) $(DYLIB) $(FLAGS) $(LIBS) -o $(NAME) -g

# Rule for compiling the bonus part of the program. We just remove the existing
# executable and recompile the normal program with the BONUS env. variable set
# to 1.
bonus:
	rm -f $(NAME)
	@BONUS=1 make $(NAME)
	@touch bonus

bonusre: fclean bonus

# Generic rule for compiling any C-file into an object file
%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES) $(LIBS) -g

# Generic rule for compiling libraries
%.a:
	make -C $(@D)

# Rules for cleaning files
clean:
	make clean -C lib/libft
	make clean -C lib/libftprintf
	make clean -C lib/libgnl
	make clean -C lib/libvec
	make clean -C lib/libvla
	rm -f $(OFILES) $(BONUS_OFILES) src/main.o

fclean: clean
	make clean -C lib/libmlx
	make fclean -C lib/libft
	make fclean -C lib/libftprintf
	make fclean -C lib/libgnl
	make fclean -C lib/libvec
	make fclean -C lib/libvla
	rm -f $(NAME)
	rm -f bonus

re: fclean all
