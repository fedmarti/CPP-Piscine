NAME=BraiiiiiiinnnzzzZ

SRC=main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

CC=c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all