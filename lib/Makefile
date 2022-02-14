REDDARK	=	\033[31;1m
RED		=	\033[31;1m
GREEN	=	\033[32;1m
YEL		=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[0m

NAME	=	libs

all:		$(NAME)

$(NAME):
		@:
		@printf "\n$(YEL)  [$(WHITE)%s$(YEL)] → $(WHITE)Compilation des libs\n" $(NAME)
		@make -C ./str
		@make -C ./ll
		@make -C ./disp
		@printf "\n$(YEL)  [$(WHITE)%s$(YEL)] → " $(NAME)
		@printf "$(WHITE)Compilation terminée.\n\n"

clean:
		@make clean -C ./str
		@make clean -C ./ll
		@make clean -C ./disp
		@printf "$(YEL)\n$(WHITE)"
		@printf "$(YEL)  [$(WHITE)%s$(YEL)] → " $(NAME)
		@printf "$(WHITE)Suppression terminée.\n\n"

fclean:		clean
		@make fclean -C ./str
		@make fclean -C ./ll
		@make fclean -C ./disp

re:		fclean all

.PHONY:		all clean fclean re