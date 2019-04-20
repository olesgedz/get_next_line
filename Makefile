# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 18:51:38 by arizzell          #+#    #+#              #
#    Updated: 2019/04/20 15:48:15 by jblack-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
FLAGS = -g -Wall -Wextra -Werror
CC = clang
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/


HEADERS_DIRECTORY = ./
HEADERS_LIST = get_next_line.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

DIRECTORY =  $(shell pwd)

SRCS_DIRECTORY = srcs/
SRCS_LIST = main.c get_next_line.c
OBJS_DIRECTORY = objects/
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIRECTORY), $(OBJS_LIST))

LIBFT = libft/libft.a
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
CLEAR_LINE	:= \033[2K
BEGIN_LINE	:= \033[A
COL_END		:= \033[0m
COL_RED		:= \033[1;31m
COL_GREEN	:= \033[1;32m
COL_YELLOW	:= \033[1;33m
COL_BLUE	:= \033[1;34m
COL_VIOLET	:= \033[1;35m
COL_CYAN	:= \033[1;36m
COL_WHITE	:= \033[1;37m

TOTAL_FILES := $(shell echo $(SRCS_LIST) | wc -w | sed -e 's/ //g')
CURRENT_FILES = $(shell find $(DIRECTORY)/objects/ -type f 2> /dev/null | wc -l | sed -e 's/ //g')

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIRECTORY) $(OBJS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJS) $(SDL_CFLAGS) $(SDL_LDFLAGS) -o $(NAME)
	@echo "$(CLEAR_LINE)[`expr $(CURRENT_FILES) '*' 100 / $(TOTAL_FILES)`%] $(COL_BLUE)[$(NAME)] $(COL_GREEN)Finished compilation. Output file : $(COL_VIOLET)$(PWD)/$(NAME)$(COL_END)"

$(OBJS_DIRECTORY):
	@mkdir -p $(OBJS_DIRECTORY)

$(OBJS_DIRECTORY)%.o: $(SRCS_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(CLEAR_LINE)[`expr $(CURRENT_FILES) '*' 100 / $(TOTAL_FILES)`%] $(COL_BLUE)[$(NAME)] $(COL_GREEN)Compiling file [$(COL_VIOLET)$<$(COL_GREEN)].($(CURRENT_FILES) / $(TOTAL_FILES))$(COL_END)$(BEGIN_LINE)"

count:
	@echo $(TOTAL_FILES)
	@echo $(CURRENT_FILES)


$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	
clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	#@$(MAKE) -sC $(SDL_MAKE) clean

dd:
	rm $(NAME)

lib:
	 @$(MAKE) -sC $(LIBSDL_DIRECTORY) re

fclean: clean
	@rm -r $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	#@rm -f $(DIRECTORY)/bin/sdl2-config
	#@rm -f $(DIRECTORY)/lib/libSDL2.la
	#@rm -f $(DIRECTORY)/lib/libSDL2main.la
	#@rm -f $(DIRECTORY)/lib/libSDL2_test.la
	#@rm -f $(DIRECTORY)/share/aclocal/sdl2.m4
	#@rm -f $(DIRECTORY)/lib/pkgconfig/sdl2.pc
	#@rm -f $(DIRECTORY)/lib/cmake/SDL2/sdl2-config.cmake
	#@rm -rf lib bin share
	#@echo "$(SDL_MAKE): $(RED)was unistalled$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

run-debug: debug
	@lldb a.out

run_simple: 
	./get_next_line  tests/a.txt
	./get_next_line  tests/a.txt  tests/b.txt
	./get_next_line  tests/no_new

run_time:
	time ./get_next_line tests/1004.txt

run_valgrind:
	valgrind ./get_next_line  tests/a.txt  tests/b.txt
	valgrind ./get_next_line tests/1004.txt