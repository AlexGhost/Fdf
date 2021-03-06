NAME = fdf
CFLAG = -Wall -Werror -Wextra
CC = gcc $(CFLAG)
SRC = main.c fdf_draw.c fdf_file.c fdf_window.c fdf_isogrid.c fdf_misc.c \
	  fdf_getcoord.c
OBJ = $(SRC:.c=.o)
POBJ = $(addprefix obj/,$(OBJ))

all : $(NAME)

$(NAME) : submake $(POBJ)
	@$(CC) $(POBJ) -Llibft -lft -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "\r\033[K"
	@echo "\033[32m/------------------------------------\ \\033[0m"
	@echo "\033[32m|------------- $(NAME) crée -------------| \\033[0m"
	@echo "\033[32m\------------------------------------/ \\033[0m"

submake :
	@$(MAKE) -C minilibx_macos/
	@$(MAKE) -C libft/

obj/%.o: %.c
	@printf "\r\033[K""\033[36m - Compilation de \033[0m$<\033[0m"
	@mkdir -p obj
	@$(CC) -o $@ -c $<

clean :
	@$(MAKE) clean -C minilibx_macos/
	@$(MAKE) fclean -C libft/
	@rm -rf obj

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31mSuppression - $(NAME)\033[0m"

re : fclean all
