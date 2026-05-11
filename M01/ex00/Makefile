# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/23 22:17:27 by ssukhija          #+#    #+#              #
#    Updated: 2026/03/23 22:17:27 by ssukhija         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
# colours
RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m

NAME = zombie

# flags
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

# files
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ = $(SRCS:.cpp=.o)

# rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
	printf "Linking executable	$(GREEN)[OK]$(RESET)\n"

%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJ)
	printf "clean object files	$(YELLOW)[OK]$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	printf "cleaning all files	$(YELLOW)[OK]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re