NAME= a

CC= gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I .

SRC= *.c

OBJ=$(SRC:.c=.o)

all:
	gcc main.c libft.a

clean:
	$(RM) $(OBJ)

main:
	gcc main.c libft.a
fclean: clean
	$(RM) $(NAME)

re: fclean all
