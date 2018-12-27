# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arizzell <arizzell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 18:51:38 by arizzell          #+#    #+#              #
#    Updated: 2018/12/28 01:20:00 by olesgedz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= get_next_line

SRC= main.c get_next_line.c
OBJ= $(SRC:.c=.o)

CC= clang
CFLAGS= -Wall -Wextra -Werror
LIBFT= ./libft/libft.a
LIBINC= -I ./libft
LIBLINK= -L./libft -lft
INC= get_next_line.h

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@make -C ./libft

$(NAME): libft $(OBJ)
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

debug: libft $(OBJ)
	@$(CC) $(LIBLINK) -g $(SRC)

remlib:
	@rm -rf $(LIBFT)

remoblib:
	@make fclean -C ./libft/

clean: remoblib
	@rm -rf $(OBJ)

fclean: clean remlib
	@rm -rf $(NAME)

re: fclean all

test: re
	@./gnl test.txt

run-debug: debug
	@lldb a.out

run: re
	./gnl test.txt
	./gnl test.txt test2.txt
