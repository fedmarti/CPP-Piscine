NAME=array

MY_NAME=mytest

SRC=main.cpp

MY_SRC=my_main.cpp

OBJ=$(SRC:%.cpp=%.o)

MY_OBJ=$(MY_SRC:%.cpp=%.o)

CC=c++

CFLAGS=-std=c++98 -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(MY_NAME): $(MY_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c $^ -I./

clean:
	rm -f $(OBJ)
	rm -f $(MY_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(MY_NAME)

re: fclean all

.PHONY: clean fclean re all