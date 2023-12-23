NAME=megaphone

C=c++

FLAGS=-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): megaphone.cpp
	$(C) $(FLAGS) $^ -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHHONY: all clean fclean re