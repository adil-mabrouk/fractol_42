# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 00:26:24 by amabrouk          #+#    #+#              #
#    Updated: 2024/03/24 12:33:58 by amabrouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
SRC = fractol.c math.c utils_fun.c put_pixel.c fractol_events.c atodbl.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -O3 $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)

%.o : %.c fractol.h
	$(CC) -O3 $(CFLAGS) -c $< -o $@

bonus : all

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all