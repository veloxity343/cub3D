# Standard
NAME		=	cub3D

# Directories
LIBFT		=	./libft/libft.a
INC			=	inc/
SRC_DIR		=	src
OBJ_DIR		=	obj
# SRCB_DIR	=	srcb
# OBJB_DIR	=	objb

# MLX
UNAME_S		:= $(shell uname -s)
MLX_LINUX	= -Lminilibx-linux -lmlx -lXext -lX11 -lm
MLX_MACOS	= -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

ifeq ($(UNAME_S), Linux)
	MLX			=	$(MLX_LINUX)
	MLX_DIR		=	./minilibx-linux
else
	MLX			=	$(MLX_MACOS)
	MLX_DIR		=	./minilibx_opengl_20191021
endif

# Compiler & flags
WFLAGS		=	-Wall -Wextra -Werror #-g3 -fsanitize=address
IFLAGS		=	-I$(INC)
DSYM		=	-g3
FSAN		=	-fsanitize=address $(DSYM)
CFLAGS		=	$(WFLAGS) $(IFLAGS)
CC			=	cc
AR			=	ar -rcs
RM			=	rm -rf

# Sources & objects
SRC			=	$(shell find $(SRC_DIR) -type f -name "*.c")
OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
# SRCB		=	$(shell find $(SRCB_DIR) -type f -name "*.c")
# OBJB		=	$(patsubst $(SRCB_DIR)%.c, $(OBJB_DIR)%.o, $(SRCB))

# Colors
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
BLUE	=	\033[1;34m
RESET	=	\033[0m

# Build rules
all:		$(LIBFT) $(NAME)
	@echo "$(GREEN)Successfully compiled!$(RESET)"

$(LIBFT):
	@echo "$(BLUE)Building$(RESET)\tlibft"
	@make -C $(dir $(LIBFT))

$(NAME):	$(OBJ)
	@echo "\n$(BLUE)Building$(RESET)\t$(NAME)"
	@make -sC $(MLX_DIR)
	@make -sC $(dir $(LIBFT))
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling\t$(RESET)%-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

# bonus:		clean $(OBJ) $(OBJB)
# 	@echo "$(BLUE)Linking bonus objects...$(RESET)"
# 	@make -C $(dir $(LIBFT))
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJB) $(LIBFT) $(MLX)
# 	@echo "$(GREEN)Successfully compiled bonus!$(RESET)"

# $(OBJB_DIR):
# 	@mkdir -p $(OBJB_DIR)

# $(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c | $(OBJB_DIR)
# 	@mkdir -p $(dir $@)
# 	@printf "$(YELLOW)Compiling\t$(RESET)%-33.33s\r" $@
# 	@$(CC) $(CFLAGS) -c $< -o $@

# Scruba dub dub
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	$(RM) -rf $(OBJ_DIR); \
	echo "$(RED)Deleting$(RESET)\t"$(OBJ_DIR); else \
	echo "$(BLUE)No $(NAME) objects to remove.$(RESET)"; \
	fi;
# @if [ -d $(OBJB_DIR) ]; then \
# $(RM) -rf $(OBJB_DIR); \
# echo "$(RED)Deleting$(RESET)\t$(OBJB_DIR)"; \
# fi;
	@make -C $(MLX_DIR) clean

fclean:	clean
	@if [ -f "$(NAME)" ]; then \
	$(RM) -f $(NAME); \
	echo "$(RED)Deleting$(RESET)\t"$(NAME); else \
	echo "$(BLUE)No executable $(NAME) to remove.$(RESET)"; \
	fi;
	@make fclean -C $(dir $(LIBFT))

re:		fclean all

# Debugging
asan:		CFLAGS	+=	$(FSAN)
asan:	
	@echo "$(YELLOW)Running with AddressSanitizer...$(RESET)"
	./$(NAME) map/valid/maze.cub

valgrind:	$(NAME)
	@echo "$(YELLOW)Running with Valgrind...$(RESET)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) map/valid/maze.cub

test:		re
	@echo "$(YELLOW)Running tests...$(RESET)"
	./$(NAME) map/valid/maze.cub

norm:
	norminette $(SRC_DIR) $(INC)
	@echo  "$(GREEN)Norminette check complete!$(RESET)"

.PHONY:	all bonus clean fclean re asan valgrind test norm
