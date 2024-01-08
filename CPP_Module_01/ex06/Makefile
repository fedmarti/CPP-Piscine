NAME=HarlFilter

SRC=main.cpp Harl.cpp

CC=c++

CFLAGS = -Wall -Wextra -Werror -Werror -std=c++98
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

re: fclean all

.PHONY: re fclean clean all