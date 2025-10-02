NAME = Mugugno

CC = c++
FLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++98

SRCS = main.cpp Harl.cpp

all: $(NAME)

$(NAME): $(SRCS)
		$(CC) $(FLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "wassup"

fclean:
	rm -f $(NAME)

re: fclean all

run: all
	clear ; ./$(NAME)

gdb: all
	clear ; gdb ./$(NAME)

val: all
	clear ; valgrind ./$(NAME)

PHONY: all clean fclean run
.SILENT: