NAME = Zoo

CC = c++
FLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++98

SRCS = main.cpp ScalarConverter.cpp ScalarConverterUtils.cpp ToPrint.cpp

# Allow passing CLI args like: make run 12 23 abc
RUN_ARGS := $(filter-out $@,$(MAKECMDGOALS))

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
	clear ; valgrind ./$(NAME)

gdb: $(NAME)
	clear ; gdb --args ./$(NAME) $(RUN_ARGS)

# Swallow extra goals used as args to 'run'
%:
	@:

.PHONY: all clean fclean run
.SILENT: