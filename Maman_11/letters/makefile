
NAME = letters

CC = gcc
CFLAGS = -ansi -Wall -pedantic

make:
	@ $(CC) $(CFLAGS) -o $(NAME) $(NAME).c

test: $(NAME)
	./$(NAME)

inputA: $(NAME)
	./$(NAME) < input_a.txt

$(NAME): $(NAME).c
	@ $(CC) $(CFLAGS) -o $(NAME) $(NAME).c