############
## COLORS ##
############

DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

###############
## VARIABLES ##
###############

NAME		=	pipex
CC			=	cc
CLFAGS		=	-Wall -Wextra -Werror -g3 -MMD
INCLUDES	=   -I./$(INCLUDE) -I./$(LIBFT)$(INCLUDE) 
SRC_DIR		=	src/
INCLUDE		=	include/
OBJ_DIR		=	obj/
LIBFT		=	Libft/
RM			=	rm -f

#############
## SOURCES ##
#############

SRC_FILES	=	main \
				utils \
				utils2

SRC			=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR)/app/, $(addsuffix .o, $(SRC_FILES)))
DEP			=	$(addprefix $(OBJ_DIR)/app/, $(addsuffix .d, $(SRC_FILES)))


#############
## RECIPES ##
#############

all:	$(NAME)

$(NAME): $(OBJ)
	@make --no-print-directory -C $(LIBFT) "OBJ_DIR=$(shell realpath $(OBJ_DIR))" libft.a
	@echo "$(YELLOW)Linking $(NAME)...$(DEF_COLOR)"
	@$(CC) $(CLFAGS) $(INCLUDES) -L./$(OBJ_DIR) $(OBJ) -lft -o $(NAME)

$(OBJ_DIR)/app/%.o:	$(SRC_DIR)%.c
	@mkdir -p $(shell dirname $@)
	@echo "$(YELLOW)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CLFAGS) $(INCLUDES) -c $< -o $@ -MMD

clean:
	@echo "$(YELLOW)Cleaning object files for $(NAME)...$(DEF_COLOR)"
	@make --no-print-directory -C $(LIBFT) clean "OBJ_DIR=$(shell realpath $(OBJ_DIR))"
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)Object for $(NAME) deleted succesfully!$(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Cleaning files for $(NAME)$(DEF_COLOR)"
	@make --no-print-directory -C $(LIBFT) fclean "OBJ_DIR=$(shell realpath $(OBJ_DIR))"
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) deleted succesfully!$(DEF_COLOR)"

re:	fclean all

-include $(DEP)

.PHONY:	all, clean, fclean, re