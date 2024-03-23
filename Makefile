# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:29:01 by tlassere          #+#    #+#              #
#    Updated: 2024/03/23 21:59:50 by tlassere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			::= cub3D

SOURCES_CONTENT ::= ft_cube

SOURCES			::= $(foreach buffer, $(SOURCES_CONTENT), sources/$(buffer).c)

OBJECTS			::= $(SOURCES:.c=.o)

CFLAGS	::= -Wall -Wextra -Werror

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all