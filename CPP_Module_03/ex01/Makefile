NAME=open!

CC=c++

CFLAGS=-Wall -Wextra -Werror -std=c++98

SRC=main.cpp ClapTrap.cpp

OBJ=$(SRC:%.cpp=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c $^

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re