NAME = pipex

LIB_DIR = libft/
LIB = libft.a

LIBFT = $(addprefix $(LIB_DIR), $(LIB)) 

INCLUDE = include/
SRC_DIR = src/

FILES = main.c pipex_utils.c childs_processes.c

OBJS = $(FILES:.c=.o)

SRC_FILES = $(addprefix $(SRC_DIR), $(FILES))
SRC_OBJS = $(addprefix $(SRC_DIR), $(OBJS))

DOTH = pipex.h
HEADER = $(addprefix $(INCLUDE), $(DOTH)) 
 
CC = gcc
CFLAGS = -Wall -Werror -Wextra 


$(NAME) : $(OBJ_DIR) $(SRC_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_OBJS)  -o $(NAME) $(LIBFT)
	

$(SRC_DIR)%.o : $(SRC_DIR)%.c 
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT) :
	@make -C $(LIB_DIR)


.PHONY : all clean fclean re

all: $(NAME)

clean : 
	@rm -f $(SRC_OBJS)
	
fclean: clean
	@rm -f $(NAME)

re : fclean all 