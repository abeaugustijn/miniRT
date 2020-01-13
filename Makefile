# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 15:41:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/01/13 15:41:58 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT
SRCS			=

LIBFT_SRCS		=

CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

LIBFT_CFILES	=	$(LIBFT_SRCS:%=libft/ft_%.c)
LIBFT_OFILES	=	$(LIBFT_SRCS:%=libft/ft_%.o)

INCLUDES		=	-I include -I libft

FLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT_OFILES)
	@echo "Linking executable"
	@gcc $(OFILES) $(LIBFT_OFILES) $(FLAGS) -o $(NAME)
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
	@rm -f $(OFILES) $(LIBFT_OFILES)

re: fclean all
