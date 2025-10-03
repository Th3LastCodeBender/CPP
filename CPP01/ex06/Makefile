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

debug: all
	clear ; ./$(NAME) debug

info: all
	clear ; ./$(NAME) info

warning: all
	clear ; ./$(NAME) warning

error: all
	clear ; ./$(NAME) error

nulla: all
	clear ; ./$(NAME)

vuoto: all
	clear ; ./$(NAME) ""

multipli: all
	clear ; ./$(NAME) "multipli giovanni"

gdb: all
	clear ; gdb ./$(NAME)

val: all
	clear ; valgrind ./$(NAME)

PHONY: all clean fclean run
.SILENT: