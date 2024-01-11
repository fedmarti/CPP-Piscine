NAME=Interface

SRC=main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp ICharacter.cpp IMateriaSource.cpp

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