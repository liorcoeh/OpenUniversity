
NAME = myset

# Finding all the files with .c
C_FILES:= $(shell find -name "*.c")

CC = gcc
CFLAGS = -ansi -Wall -pedantic
CMORE = -lm

VALGRIND = valgrind --leak-check=yes --track-origins=yes

# General "make" - will create the executable file
make:
	@ $(CC) $(CFLAGS) -o $(NAME) $(C_FILES)

# "make test" - will create executable and will run it
test: $(NAME)
	@ ./$(NAME)

ainput: $(NAME)
	@ ./$(NAME) < input_a.txt

# "make vlg" - will create executable and will run it using valgrind
vlg: $(NAME)
	@ $(VALGRIND) ./$(NAME)

# Will create executable for the "make test" and "make vlg"
$(NAME): $(C_FILES)
	@ $(CC) $(CFLAGS) -o $(NAME) $(C_FILES)