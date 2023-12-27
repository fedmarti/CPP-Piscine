NAME=fixed

TESTOUTPUT = "Default constructor called\nInt constructor called\nFloat constructor called\nCopy constructor called\nCopy assignment operator called\nFloat constructor called\nCopy assignment operator called\nDestructor called\na is 1234.43\nb is 10\nc is 42.4219\nd is 10\na is 1234 as integer\nb is 10 as integer\nc is 42 as integer\nd is 10 as integer\nDestructor called\nDestructor called\nDestructor called\nDestructor called"

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