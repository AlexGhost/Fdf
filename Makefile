NAME = fdf
CFLAG = -Wall -Werror -Wextra
CC = gcc $(CFLAG)
SRC = main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : submake $(OBJ)
	@$(CC) $(OBJ) -Ilibft/ -Llibft -lft -o $(NAME)
	@printf "\r\033[K"
	@echo "\033[32m/------------------------------------\ \\033[0m"
	@echo "\033[32m|------------- $(NAME) crée -------------| \\033[0m"
	@echo "\033[32m\------------------------------------/ \\033[0m"

cpp : submake
	@cpp $(CFLAG) $(SRC) -Ilibft/ -Llibft -lft -o $(NAME)

submake :
	@$(MAKE) -C libft/

%.o: %.c
	@printf "\r\033[K""\033[36m - Compilation de \033[0m$<\033[0m"
	@$(CC) -o $@ -c $< -Ilibft

clean :
	@$(MAKE) fclean -C libft/
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31mSuppression - $(NAME)\033[0m"

re : fclean all
