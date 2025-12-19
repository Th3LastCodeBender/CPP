NAME = Zoo

CC = c++
FLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++98

SRCS = main.cpp

all: $(NAME)

$(NAME): $(SRCS)
		$(CC) $(FLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "wassup"

fclean:
	rm -f $(NAME)

re: fclean all

run: re
	clear ; ./$(NAME)

val: $(NAME)
	clear ; valgrind ./$(NAME)

PHONY: all clean fclean run
.SILENT: