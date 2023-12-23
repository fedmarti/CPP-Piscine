NAME=SuperCoolPB

C=c++

FLAGS=-Wall -Wextra -Werror -std=c++98

SRC= main.cpp

OBJS= $($SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(FLAGS) $^ -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHHONY: all clean fclean re
