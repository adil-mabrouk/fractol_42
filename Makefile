# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 00:26:24 by amabrouk          #+#    #+#              #
#    Updated: 2024/03/27 03:31:45 by amabrouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
BONUS_NAME = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

SRC = Mandatory_part/fractol.c Mandatory_part/math.c Mandatory_part/utils_fun.c\
	Mandatory_part/put_pixel.c Mandatory_part/fractol_events.c Mandatory_part/atodbl.c
OBJ = $(SRC:%.c=%.o)

SRC_BONUS = Bonus_part/fractol_bonus.c Bonus_part/math_bonus.c Bonus_part/utils_fun_bonus.c\
	Bonus_part/put_pixel_bonus.c Bonus_part/fractol_events_bonus.c Bonus_part/atodbl_bonus.c
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -O3 $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)

Mandatory_part/%.o : Mandatory_part/%.c Mandatory_part/fractol.h
	$(CC) -O3 $(CFLAGS) -c $< -o $@

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(OBJ_BONUS)
	$(CC) -O3 $(CFLAGS) $(MLX) $(OBJ_BONUS) -o $(BONUS_NAME)

Bonus_part/%.o : Bonus_part/%.c Bonus_part/fractol_bonus.h
	$(CC) -O3 $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

re : fclean all