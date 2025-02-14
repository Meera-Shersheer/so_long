SRC= ft_chars_a.c ft_chars_b.c ft_mem_a.c ft_mem_b.c ft_puts.c ft_string_a.c ft_string_b.c ft_string_c.c ft_split.c ft_printf.c put_printf.c support_printf.c \
get_next_line_bonus.c get_next_line_utils_bonus.c
BNS= ft_linked_lists_a_bonus.c ft_linked_lists_b_bonus.c
NAME = libft.a

CC= cc

CFLAGS= -Wall -Wextra -Werror -g

OBJECTDIR := objects

OBJ_SRC = $(addprefix $(OBJECTDIR)/, $(SRC:.c=.o))
OBJ_BNS = $(addprefix $(OBJECTDIR)/, $(BNS:.c=.o))

all: $(NAME)

$(NAME): | $(OBJ_SRC)
	ar rcs $(NAME) $(OBJ_SRC)


$(OBJECTDIR)/%.o: %.c
	@mkdir -p $(OBJECTDIR) 
	$(CC) $(CFLAGS) -c $< -o $@

bonus:  $(NAME) $(OBJ_BNS)
	ar rcs $(NAME) $(OBJ_SRC) $(OBJ_BNS)

clean:
	rm -rf $(OBJECTDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus       	

# SRC= ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_bzero.c ft_putnbr_fd.c \
# ft_strlcpy.c ft_tolower.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
# ft_isalnum.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalpha.c ft_memcpy.c ft_strchr.c \
# ft_strncmp.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isdigit.c ft_memset.c \
# ft_striteri.c ft_strrchr.c ft_isprint.c ft_putchar_fd.c	ft_strjoin.c ft_strtrim.c \
# ft_printf.c support_printf.c put_printf.c get_next_line_bonus.c get_next_line_utils_bonus.c

# HEADERS= libft.h ft_printf.h get_next_line_bonus.h

# BNS= ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
# ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c


# NAME = libft.a
# CC= cc

# CFLAGS= -Wall -Wextra -Werror -g

# OBJ_SRC= $(SRC:.c=.o)

# OBJ_BNS= $(BNS:.c=.o)

# all: $(NAME) 
# 	mkdir -p source_files && mv $(SRC) $(BNS)   ./source_files
# 	mkdir -p object_files && mv $(OBJ_SRC) ./object_files
# 	mkdir -p header_files && mv $(HEADERS) ./header_files
	

# $(NAME):  $(OBJ_SRC)
# 	ar rcs $(NAME) $(OBJ_SRC)
	
# bonus:  $(NAME) $(OBJ_BNS)
# 	ar rcs $(NAME) $(OBJ_BNS)
# 	mkdir -p source_files && mv  $(SRC)  $(BNS) ./source_files
# 	mkdir -p object_files && mv $(OBJ_BNS) $(OBJ_SRC) ./object_files
# 	mkdir -p header_files && mv $(HEADERS) ./header_files
	

# clean:
# 	rm -f $(OBJ_SRC) $(OBJ_BNS)
# 	cd object_files && rm -f $(OBJ_SRC) $(OBJ_BNS) || echo "Directory does not exist"
# 	cd source_files && mv $(SRC) $(BNS) ..  || echo "Directory does not exist"
# 	cd header_files && mv $(HEADERS) ..  || echo "Directory does not exist"
# 	rm -rf header_files object_files source_files

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re bonus       	
