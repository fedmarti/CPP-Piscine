NAME=firstCanon

TESTOUTPUT = "Default constructor called\nCopy constructor called\nCopy assignment operator called\\ngetRawBits member function called\nDefault constructor called\nCopy assignment operator called\ngetRawBits member function called\ngetRawBits member function called\n0\ngetRawBits member function called\n0\ngetRawBits member function called\n0\nDestructor called\nDestructor called\nDestructor called"

CC=c++

CFLAGS=-Wall -Wextra -Werror -std=c++98

SRC=main.cpp Fixed.cpp

OBJ=$(SRC:%.cpp=%.o)

%.o:%.cpp
	$(CC) $(CFLAGS) $^ -c -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

test: $(NAME)
	./$(NAME) > myout
	@echo $(TESTOUTPUT) > outputref
	diff outputref myout

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f myout
	rm -f outputref

re: fclean all

.PHONY: re fclean clean all test