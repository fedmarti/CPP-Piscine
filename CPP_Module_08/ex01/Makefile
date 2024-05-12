NAME=span

SRC=main.cpp Span.cpp

OBJ=$(SRC:%.cpp=%.o)

CC=c++

CFLAGS=-std=c++98 -Wall -Wextra -Werror -g

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all