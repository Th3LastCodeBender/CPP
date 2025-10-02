NAME = FonBuk

CC = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SRCS = mapb.cpp contact.cpp phonebook.cpp

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

PHONY: all clean fclean run more zero
.SILENT:
