NAME=SuperCoolPB

CC=c++

CFLAGS=-Wall -Wextra -Werror -std=c++98 -g

SRC= main.cpp Phonebook.cpp Contact.cpp

OBJS= $(SRC:%.cpp=%.o)

all: $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) $^ -c

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHHONY: all clean fclean re
