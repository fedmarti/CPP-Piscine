NAME = tests

SRC = Account.cpp tests.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:

test: $(NAME)
	./$(NAME) > my.log
	awk '{print $$2}' my.log > mytruncated
	awk '{print $$2}' 19920104_091532.log > originaltruncated
	diff mytruncated originaltruncated
	rm -f mytruncated originaltruncated my.log
	

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test