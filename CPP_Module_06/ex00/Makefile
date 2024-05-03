NAME=scalar_types

SRC=main.cpp ScalarConverter.cpp

OBJ=$(SRC:%.cpp=%.o)

CFLAGS=-std=c++98 -Wall -Wextra -Werror

CC=c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CLFAGS) -o $@ $^

.o:.cpp
	$(CC) $(CLFAGS) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
