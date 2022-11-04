##
## EPITECH PROJECT, 2022
## BSQ
## File description:
## Makefile
##

REDDARK	=	\033[31;1m
RED		=	\033[31;1m
GREEN	=	\033[32;1m
YEL		=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[0m

SRC		=	src/main.c				\
			src/start.c				\
			src/bsq.c				\
			src/utils.c				\
			src/disp.c				\
			
RM		=	rm -f
CC		=	gcc
CFLAGS	+=	-O3 -Wall $(INC) -Wextra
INC		=	-I./include
NAME	=	bsq
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)
		@:
		@printf "\n$(GREEN)  [$(WHITE)%s$(GREEN)] → " $(NAME)
		@printf "$(WHITE)Compilation terminée. "
		@printf "$ Binaire : $(CYAN) ./%s$(WHITE)\n\n" $(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

%.o:		%.c
		@$(CC) $(CFLAGS) -o $@ -c $<
		@printf "$(GREEN)[$(WHITE)%s$(GREEN)] — $(WHITE)%-45s\n" $(NAME) $<
		@printf "$(GREEN) → $(RES) %-70s" $@
		@printf "$(GREEN)[$(WHITE)√$(GREEN)]\n"

clean:
		@$(RM) $(OBJ)
		@printf "$(GREEN)\n$(WHITE)"
		@printf "$(GREEN)  [$(WHITE)%s$(GREEN)] → " $(NAME)
		@printf "$(WHITE)Suppression terminée.\n\n"

fclean:	
		@$(RM) $(OBJ)
		@$(RM) $(NAME)
		@printf "$(GREEN)\n$(WHITE)"
		@printf "$(GREEN)  [$(WHITE)%s$(GREEN)] → " $(NAME)
		@printf "$(WHITE)Suppression terminée.\n\n"

re:			fclean all

.PHONY:		all clean fclean re