NAME=Polymorphism

SRC=main.cpp Animal.cpp Dog.cpp Cat.cpp

OBJ=$(SRC:%.cpp=%.o)

CC=c++

CFLAGS=-Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

all:$(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all