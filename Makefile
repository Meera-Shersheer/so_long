SRC= 
BNS= 

NAME = so_long
INC=/usr/include
CC= cc
CFLAGS= -Wall -Wextra -Werror -g

#PATH LIB
LFTDIR= ./Libft

## create an object dir 
OBJ_DIR := obj

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BNS = $(addprefix $(OBJ_DIR)/, $(BNS:.c=.o))

all: $(NAME)

$(NAME):| libft $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -I/usr/include -Imlx_linux -O3 -o $(NAME) -L$(LFTDIR) -lft 



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
