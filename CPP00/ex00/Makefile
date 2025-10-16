NAME = megaphone

CC = c++
FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SRCS = megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS)
		$(CC) $(FLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "wassup"

fclean:
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	clear ; ./$(NAME) "oliooooooo spoooorco"

more: $(NAME)
	clear ; ./$(NAME) "SpoooOOORco" " " "VELENo"

zero: $(NAME)
	clear ; ./$(NAME)
