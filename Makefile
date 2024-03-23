# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:29:01 by tlassere          #+#    #+#              #
#    Updated: 2024/03/23 22:35:52 by tlassere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			::= cub3D

SOURCES_CONTENT ::= ft_cube

SOURCES			::= $(foreach buffer, $(SOURCES_CONTENT), sources/$(buffer).c)

OBJECTS			::= $(SOURCES:.c=.o)

HEADER			::= headers

LIBFT_DIR		::= libft

LIBFT			::= $(LIBFT_DIR)/libft.a

CFLAGS			::= -Wall -Wextra -Werror

LDFLAGS			::= $(CFLAGS) -lm

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT_DIR) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJECTS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

$(LIBFT):
	make -C libft

re: fclean all