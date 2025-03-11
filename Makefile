# Standard
NAME		=	cub3D

# Directories
LIBFT		=	./libft/libft.a
INC			=	inc/
SRC_DIR		=	src
OBJ_DIR		=	obj
SRCB_DIR	=	srcb
OBJB_DIR	=	objb

# MLX
UNAME_S		:= $(shell uname -s)
MLX_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -lmlx -framework OpenGL -framework AppKit

ifeq ($(UNAME_S), Darwin)
	MLX		= $(MLX_MACOS)
else
	MLX		= $(MLX_LINUX)
	MLX_CO	= $(MLX_LINUX)
endif

# Compiler & flags
# WFLAGS		=	-Wall -Wextra -Werror
WFLAGS		=	
IFLAGS		=	-I$(INC)
DSYM		=	-g3
FSAN		=	-fsanitize=address $(DSYM)
CFLAGS		=	$(WFLAGS) $(IFLAGS)
CC			=	gcc
AR			=	ar -rcs
RM			=	rm -rf

# Sources & objects
SRC			=	$(shell find $(SRC_DIR) -type f -name "*.c")
OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
SRCB		=	$(shell find $(SRCB_DIR) -type f -name "*.c")
OBJB		=	$(patsubst $(SRCB_DIR)%.c, $(OBJB_DIR)%.o, $(SRCB))

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
	@make -s -C $(dir $(LIBFT))
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling\t$(RESET)%-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:		clean $(OBJ) $(OBJB)
	@echo "$(BLUE)Linking bonus objects...$(RESET)"
	@make -C $(dir $(LIBFT))
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJB) $(LIBFT) $(MLX)
	@echo "$(GREEN)Successfully compiled bonus!$(RESET)"

$(OBJB_DIR):
	@mkdir -p $(OBJB_DIR)

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c | $(OBJB_DIR)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling\t$(RESET)%-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

# Scruba dub dub
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	$(RM) -rf $(OBJ_DIR); \
	echo "$(RED)Deleting$(RESET)\t"$(OBJ_DIR); else \
	echo "$(BLUE)No $(NAME) objects to remove.$(RESET)"; \
	fi;
	@if [ -d $(OBJB_DIR) ]; then \
	$(RM) -rf $(OBJB_DIR); \
	echo "$(RED)Deleting$(RESET)\t$(OBJB_DIR)"; \
	fi;

fclean:	clean
	@if [ -f "$(NAME)" ]; then \
	$(RM) -f $(NAME); \
	echo "$(RED)Deleting$(RESET)\t"$(NAME); else \
	echo "$(BLUE)No executable $(NAME) to remove.$(RESET)"; \
	fi;
	@make fclean -C $(dir $(LIBFT))

re:		fclean all

# Debugging
asan:	CFLAGS	+=	$(FSAN)
asan:	re
	@echo "$(YELLOW)Running with AddressSanitizer...$(RESET)"
	./$(NAME)

norm:
	norminette

.PHONY:	all bonus clean fclean re asan norm

# CFLAG = -Wall -Wextra -Werror
# NAME = cub3D

# LIBS = ./libft/libft.a -L./libft -lft -L./minilibx-linux/ -lmlx -lmlx_Linux -lX11 -lXext -lm

# SRCS_PATH = ./src/

# SRCS = $(SRCS_PATH)main.c \
# 	$(SRCS_PATH)check_cub_file/is_invaild.c \
# 	$(SRCS_PATH)check_cub_file/utils.c \
# 	$(SRCS_PATH)validate/valid_file.c \
# 	$(SRCS_PATH)check_cub_file/init_rgb.c \
# 	$(SRCS_PATH)game/game_controls.c \
# 	$(SRCS_PATH)validate/valid_map.c \
# 	$(SRCS_PATH)validate/valid_map2.c \
# 	$(SRCS_PATH)init.c \
# 	$(SRCS_PATH)utils/exit.c \
# 	$(SRCS_PATH)utils/err_getter.c 


# OBJS = $(SRCS:.c=.o)

# all:$(NAME)

# %.o: %.c
# 	@gcc -c $< -o $@

# $(NAME): $(OBJS)
# 	@echo compling cub3D...
# 	@gcc -o $(NAME) $(OBJS) $(LIBS)
# 	@echo Hi cub3D

# clean:
# 	@rm -rf $(OBJS)
# 	@echo clean *.o

# fclean: clean
# 	@rm -rf $(NAME)
# 	@echo bye $(NAME)

# re: fclean all

# ft:
# 	@make -C ./libft --no-print-directory

# cft:
# 	@make fclean -C ./libft --no-print-directory 

# mlx:
# 	@make -C ./minilibx-linux/ --no-print-directory

# cmlx:
# 	@make clean -C ./minilibx-linux/ --no-print-directory

# r: $(NAME)
# 	valgrind --leak-check=full --track-origins=yes ./cub3D ./map/ok.cub
