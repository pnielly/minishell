NAME=minishell
CC=gcc
FLAGS=-Wall -Wextra -Werror
INC=-I includes
SRC=$(wildcard utils/*.c) $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)

all: $(NAME)
	@printf "\nCompilation completed\n"
	@printf "Type \"./$(NAME)\" to launch $(NAME)\n"

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(INC) -o $@

%.o: %.c
	@printf "Compiling ...\r"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo Object files removed.

fclean:	clean
	@rm -f $(NAME)
	@echo Executable and object files removed.

re: fclean all
