# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/26 14:12:25 by ssukhija          #+#    #+#              #
#    Updated: 2026/03/26 14:12:25 by ssukhija         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#colours
RESET = \033[;0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m

NAME = attack

#flags
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

#files
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
	printf "Linking executable $(GREEN)[OK]$(RESET)\n"

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	printf "Cleaning object files $(YELLOW)[OK]$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	printf "Cleaning all $(YELLOW)[OK]$(RESET)\n"

re: fclean all

.PHONY: re clean fclean all


