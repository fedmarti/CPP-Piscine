NAME=bsp

CC=c++

CFLAGS=-Wall -Wextra -Werror -std=c++98 -g

SRC=main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ=$(SRC:%.cpp=%.o)

%.o:%.cpp
	$(CC) $(CFLAGS) $^ -c -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TEST): Fixed.o manual.o
	$(CC) $(CFLAGS) -o $@ $^

test: $(NAME)
	./$(NAME) > myout
	@echo $(TESTOUTPUT) > outputref
	diff outputref myout

manual: $(TEST)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f myout
	rm -f outputref
	rm -f $(TEST)

re: fclean all

.PHONY: re fclean clean all test manual