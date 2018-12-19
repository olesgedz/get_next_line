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
	gcc -g main.c libft.a

clean:
	$(RM) $(OBJ)

main:
	gcc -g main.c libft.a
fclean: clean
	$(RM) $(NAME)

re: fclean all
