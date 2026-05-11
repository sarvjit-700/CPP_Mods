# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 09:06:23 by ssukhija          #+#    #+#              #
#    Updated: 2026/03/25 09:06:23 by ssukhija         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

# colours
RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m

NAME = brain

# flags
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

# files
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

#rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
	printf "Linking executable $(GREEN)[ok]$(RESET)\n"

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	printf "Cleaning object files$(YELLOW)[ok]$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	printf "Cleaning executable $(YELLOW)[ok]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
