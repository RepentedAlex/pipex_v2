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
OBJ_DIR	=	obj/
LIBFT	=	Libft/
RM		=	rm -f

#############
## SOURCES ##
#############

SRC_FILES	=	main \
				utils

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILES), $(addsuffix .o, $(SRC_FILES)))

OBJF		= .cache_exists

#############
## RECIPES ##
#############

all:	$(NAME)

$(NAME):
	@make -C $(LIBFT)
	@



$(OBJF):
	@echo "$(BLUE)Creating $@ folder...$(DEF_COLOR)"
	@mkdir -p $(addprefix $(OBJ_DIR), $(dir $(SRC_FILES)))
	@touch $@
	@echo "$(BLUE)$@ folder created succesfully!$(DEF_COLOR)"

clean:
	@make -C $(LIBFT) clean
	@$(RM) -r ./obj/
	@$(RM) .cache_exists

fclean:	clean
	@