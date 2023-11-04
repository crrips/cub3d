NAME	=	cub3D

SRC		=	main.c parsing.c print.c getters.c setters.c pars_utils.c\
			config.c map.c\
			get_next_line.c get_next_line_utils.c
	
OBJ_DIR	=	obj
OBJ		= 	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

FLAGS	=	-Wall -Werror -Wextra -g

INC		=	-I libft

HEADERS	=	cub3d.h get_next_line.h

RED		=	\033[31m
YELLOW	=	\033[33m
GREEN	=	\033[32m
END		=	\033[0m

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@cc $(FLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@cc $(FLAGS) $(INC) $(OBJ) libft/libft.a -o $@
	@echo "$(GREEN)Executable file $(NAME) was compiled!$(END)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Object files were deleted!$(END)"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Executable file was deleted!$(END)"

re: fclean all
	@echo "$(GREEN)Project was reloaded!$(END)"

.PHONY: all clean fclean re