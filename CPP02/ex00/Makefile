NAME = Zombini

CC = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: $(NAME)

$(NAME): $(SRCS)
		$(CC) $(FLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

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