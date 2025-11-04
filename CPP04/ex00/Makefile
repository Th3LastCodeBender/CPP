NAME = Zoo

CC = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp

all: $(NAME)

$(NAME): $(SRCS)
		$(CC) -DDEBUG=1 $(FLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

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