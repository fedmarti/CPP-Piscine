NAME=sreplace
SRC=main.cpp

CC=c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o "$@" $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f *.replace

re: fclean all

.PHONY: re fclean clean all