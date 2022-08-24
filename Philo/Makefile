# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 14:09:30 by moulmado          #+#    #+#              #
#    Updated: 2022/08/22 11:37:03 by moulmado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Philo

INC = src/philosopher.h

SRC_PATH = src
SRC_NAME = philosopher.c args_management.c taking_forks.c death_watcher.c \
		lyfe_cycle.c philo_state_change.c tools.c destruction.c putstr_fd_x.c
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))


OBJ = $(SRC:.c=.o)

CC = CC
CFLAGS = -Wall -Wextra -Werror -pthread

RM = @rm -rf

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean :
	$(RM) $(OBJ)
	@echo "Cleaned"

fclean :
	$(RM) $(OBJ) $(NAME)
	@echo "Fully cleaned"
	
re : fclean all
