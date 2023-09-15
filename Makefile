NAME = pipex

LIB_DIR = libft/
LIB = libft.a

LIBFT = $(addprefix $(LIB_DIR), $(LIB)) 

INCLUDE = include/

SRC_DIR = src/
FILES = main.c pipex_utils.c childs_processes.c
SRC_FILES = $(addprefix $(SRC_DIR), $(FILES))

OBJ_DIR = obj/
OBJS = $(FILES:.c=.o)
SRC_OBJS = $(addprefix $(OBJ_DIR), $(OBJS))

DOTH = pipex.h
HEADER = $(addprefix $(INCLUDE), $(DOTH)) 
 
CC = gcc
CFLAGS = -Wall -Werror -Wextra 

#Colors
RESET = "\033[0;m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"

$(NAME) : $(OBJ_DIR) $(SRC_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_OBJS)  -o $(NAME) $(LIBFT)
	@echo $(GREEN) [*] Pipex binary has been compiled! $(RESET)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@echo $(YELLOW) [*] Generating $@ ... $(RESET)

$(OBJ_DIR) : 
	@mkdir obj
	@echo $(GREEN) [*] Object dir for pipex created! $(RESET)
 
$(LIBFT) :
	@make -C $(LIB_DIR)


.PHONY : all clean fclean re

all: $(NAME)

clean : 
	@rm -f $(SRC_OBJS)
	@echo $(GREEN) [*] Objects from pipex removed!

	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf "$(OBJ_DIR)"; \
	fi

	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN) Binary pipex removed! $(RESET)
	@rm -f $(LIBFT)

re : fclean all 