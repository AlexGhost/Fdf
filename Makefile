NAME = fdf
CFLAG = -Wall -Werror -Wextra
CC = gcc $(CFLAG)
SRC = main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : submake $(OBJ)
	@$(CC) $(OBJ) -Llibft -lft -Lminilibx_macos -lmlx -o $(NAME)
	@printf "\r\033[K"
	@echo "\033[32m/------------------------------------\ \\033[0m"
	@echo "\033[32m|------------- $(NAME) crée -------------| \\033[0m"
	@echo "\033[32m\------------------------------------/ \\033[0m"

submake :
	@$(MAKE) -C minilibx_macos/
	@$(MAKE) -C libft/

%.o: %.c
	@printf "\r\033[K""\033[36m - Compilation de \033[0m$<\033[0m"
	@$(CC) -o $@ -c $<

clean :
	@$(MAKE) clean -C minilibx_macos/
	@$(MAKE) fclean -C libft/
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31mSuppression - $(NAME)\033[0m"

re : fclean all
