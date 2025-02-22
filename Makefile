SRC= parse_map.c so_long.c check_map.c check_path.c images_handling.c images_handling_2.c game.c
BNS= parse_map_bonus.c so_long_bonus.c check_map_bonus.c check_path_bonus.c images_handling_bonus.c images_handling_2_bonus.c \
game_bonus.c game_2_bonus.c game_3_bonus.c

NAME = so_long
CC= cc
CFLAGS= -Wall -Wextra -Werror -g3
BNS_NAME = so_long
#PATH LIB
LFTDIR= ./Libft

## create an object dir 
OBJ_DIR := obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BNS = $(addprefix $(OBJ_DIR)/, $(BNS:.c=.o))

all: $(NAME)

$(NAME):| libft $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME) -L$(LFTDIR) -lft  -Lminilibx-linux -lmlx -lXext -lX11 -Iminilibx-linux

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

libft: 
	@$(MAKE) -sC $(LFTDIR) bonus

clean:
	@rm -rf $(OBJ_SRC) $(OBJ_DIR)
	@$(MAKE) -sC $(LFTDIR) clean

bonus:| libft $(OBJ_BNS)
	$(CC) $(CFLAGS) $(OBJ_BNS) -o $(BNS_NAME) -L$(LFTDIR) -lft  -Lminilibx-linux -lmlx -lXext -lX11 -Iminilibx-linux

fclean: clean
	@rm -f $(OBJ_SRC) 
	@$(MAKE) -C $(LFTDIR) fclean 
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus      	
