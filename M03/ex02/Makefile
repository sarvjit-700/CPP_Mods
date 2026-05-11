# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/07 18:42:48 by ssukhija          #+#    #+#              #
#    Updated: 2026/04/07 18:42:48 by ssukhija         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#colours
RESET = \033[;0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m

#name
NAME = claptrap

#flags
CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
RM = rm -rf

#files
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ = $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
	printf "Linking executable $(GREEN)[ok]$(RESET)\n"

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	printf "Clean object files $(YELLOW)[ok]$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	printf "Clean all $(YELLOW)[ok]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
