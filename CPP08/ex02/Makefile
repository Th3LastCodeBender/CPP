NAME = Zoo

CC = c++
FLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++98

SRCS = main.cpp MutantStack.cpp

# Allow passing CLI args like: make run 12 23 abc
# Exclude known make targets from being forwarded
RUN_ARGS := $(filter-out run val all clean fclean gdb re,$(MAKECMDGOALS))

all: $(NAME)

$(NAME): $(SRCS)
		$(CC) $(FLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "wassup"

fclean:
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	clear ; ./$(NAME) $(RUN_ARGS)

val: $(NAME)
	clear ; valgrind ./$(NAME) $(RUN_ARGS)

gdb: $(NAME)
	clear ; gdb --args ./$(NAME) $(RUN_ARGS)

.PHONY: all clean fclean run val gdb

#regola che non fa interpretare come target le parole non riconosciute come comandi make
%:
	@:

.SILENT: