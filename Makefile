NAME = fillit
SRC = main.c add_remove.c check.c elems.c read.c small.c
SRCO = main.o add_remove.o check.o elems.o read.o small.o

all: $(NAME)

$(NAME): $(SRCO)
	gcc -Wall -Wextra -Werror $(SRC) -I fillit.h -o fillit

clean:
	rm -f $(SRCO)

fclean: clean
	rm $(NAME)

re: fclean $(NAME)