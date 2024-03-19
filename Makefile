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

NAME	=	pipex
CC		=	gcc
CLFAGS	=	-Wall -Wextra -Werror
SRC_DIR	=	src/
INCLUDE	=	include/
OBJ_DIR	=	obj/
LIBFT	=	Libft/
RM		=	rm -f

#############
## SOURCES ##
#############

SRC_FILES	=	main \
				utils

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		= .cache_exists

#############
## RECIPES ##
#############

all:	$(NAME)

$(NAME): $(OBJF) $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CLFAGS) -I./$(INCLUDE) -I./$(LIBFT)$(INCLUDE) -L./$(LIBFT) $(OBJ) -lft -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CLFAGS) -I./$(INCLUDE) -I./$(LIBFT)/$(INCLUDE) -c $< -o $@

$(OBJF):
	@echo "$(BLUE)Creating $@ folder...$(DEF_COLOR)"
	@mkdir -p $(addprefix $(OBJ_DIR), $(dir $(SRC_FILES)))
	@touch $@
	@echo "$(BLUE)$@ folder created succesfully!$(DEF_COLOR)"

clean:
	@echo "$(YELLOW)Cleaning object files for $(NAME)...$(DEF_COLOR)"
	@make -C $(LIBFT) clean
	@$(RM) -r ./obj/
	@$(RM) .cache_exists
	@echo "$(GREEN)Object for $(NAME) deleted succesfully!$(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Cleaning files for $(NAME)$(DEF_COLOR)"
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) deleted succesfully!$(DEF_COLOR)"

re:	fclean all

.PHONY:	all, clean, fclean, re