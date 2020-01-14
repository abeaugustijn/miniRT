# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 15:41:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/01/14 12:22:05 by aaugusti         ###   ########.fr        #
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
					libft/ft_putstr_fd\
					libft/ft_strlen

CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

INCLUDES		=	-I include -I src/libft -I src/gnl

FLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Linking executable"
	@gcc $(OFILES) $(FLAGS) -o $(NAME)
	@echo "Done"

%.o: %.c
	@echo "Compiling: $<"
	@clang -o $@ -c $< $(FLAGS) $(INCLUDES) -g

clean: _clean
	@echo "Cleaning..."

fclean: _clean
	@echo "Cleaning..."
	@rm -f $(NAME)

_clean:
	@rm -f $(OFILES)

re: fclean all
