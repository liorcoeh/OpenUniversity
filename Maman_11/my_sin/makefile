
NAME = my_sin

CC = gcc
CFLAGS = -ansi -Wall -pedantic
CMORE = -lm

make:
	@ $(CC) $(CFLAGS) -o $(NAME) $(NAME).c $(CMORE)

test: $(NAME)
	./$(NAME)

$(NAME): $(NAME).c
	@ $(CC) $(CFLAGS) -o $(NAME) $(NAME).c $(CMORE)