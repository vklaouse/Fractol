#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 18:25:08 by vklaouse          #+#    #+#              #
#    Updated: 2016/03/14 21:39:43 by vklaouse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC = main.c mandelbrot.c keyboard.c colors.c julia.c mouse.c lapin.c burning_ship.c\
	colors_bis.c ft_motion.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

$(NAME):
	@make -C libft/ fclean && make -C libft
	@make -C minilibx_macos/ clean && make -C minilibx_macos
	@$(CC) $(FLAGS) $(SRC) -c -I./ft_printf
	@$(CC) -o $(NAME) $(OBJ) -L./minilibx_macos -lmlx -framework OpenGL -framework Appkit -L./libft -lft
	@echo "\033[33mFractol\033[m ====>\033[m \033[32m./fractol :\033[m \033[36m  Ready!\033[m"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@make -C libft/ clean
	@echo "\033[33mFractol\033[m ====>\033[m \033[32mFiles .o :\033[m \033[36m rm -f!\033[m"

fclean: clean
	@$(RM) $(NAME)
	@make -C libft/ fclean
	@make -C minilibx_macos/ clean
	@echo "\033[33mFractol\033[m ====>\033[m \033[32m./fractol :\033[m \033[36m  rm -f!\033[m"

re: fclean all

.PHONY: all clean fclean re