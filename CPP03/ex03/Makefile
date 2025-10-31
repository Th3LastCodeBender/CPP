NAME = Il_lascito_ai_nipotini

CC = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

all: $(NAME)

$(NAME): $(SRCS)
		$(CC) -DDEBUG=1 $(FLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "wassup"

fclean:
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	clear ; ./$(NAME)

val: $(NAME)
	clear ; valgrind ./$(NAME)

PHONY: all clean fclean run
.SILENT: