SRC= parse_map.c so_long.c check_map.c check_path.c images_handling.c images_handling_2.c
BNS= 

NAME = so_long
INC=/usr/include
CC= cc
CFLAGS= -Wall -Wextra -Werror -g3

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

fclean: clean
	@rm -f $(OBJ_SRC) 
	@$(MAKE) -C $(LFTDIR) fclean 
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re libft       	
