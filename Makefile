# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:29:01 by tlassere          #+#    #+#              #
#    Updated: 2024/03/23 23:14:02by tlassere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			::= cub3D

SOURCES_CONTENT ::= ft_cube

SOURCES			::= $(foreach buffer, $(SOURCES_CONTENT), sources/$(buffer).c)

OBJECTS			::= $(SOURCES:.c=.o)

HEADER			::= headers

LIBMLX			::= ./MLX42

LIBFT_DIR		::= libft

LIBFT			::= $(LIBFT_DIR)/libft.a

CFLAGS			::= -Wall -Wextra -Werror

MLX_C			::= $(LIBMLX)/build/libmlx42.a

LDFLAGS			::= $(MLX_C) -lm -ldl -lglfw -pthread

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT_DIR) -I$(LIBMLX)/include -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX_C)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean
	rm -rf $(LIBMLX)/build
	rm -f $(OBJECTS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

$(MLX_C):
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	make -C libft

re: fclean all

.PHONY: all clean fclean re
