# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 14:09:30 by moulmado          #+#    #+#              #
#    Updated: 2022/08/13 13:43:17 by moulmado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Philo

INC_PATH = inc
INC_NAME = philosopher.h
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

SRC_PATH = src
SRC_NAME = philosopher.c args_management.c taking_forks.c death_watcher.c \
		droping_forks.c lyfe_cycle.c philo_state_change.c tools.c destruction.c \
		putstr_fd_x.c
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH = obj
# OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ	= $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

CC = CC
CFLAGS = -Wall -Wextra -Werror -pthread

RM = @rm -rf

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

# $(NAME) : $(OBJ) $(INC)
# 	$(CC) $(OBJ) -o $(NAME)

# $(OBJ) : $(SRC) $(INC)
# 	@mkdir -p $(OBJ_PATH)
# 	$(CC) $(CFLAGS) -I $(INC_PATH) -o $@ -c $<

clean :
	$(RM) $(OBJ) $(OBJ_PATH)
	@echo "Cleaned"

fclean :
	$(RM) $(OBJ) $(OBJ_PATH) $(NAME)
	@echo "Fully cleaned"
	
re : fclean all