NAME= a

CC= gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I .

SRC= *.c

OBJ=$(SRC:.c=.o)

all: $(CC) $(CFLAGS) $(SRC) libft.a 

clean:
	$(RM) $(OBJ)

main:
	(gcc -c -Wall -Werror -Wextra *.c *.a)
fclean: clean
	$(RM) $(NAME)

re: fclean all
