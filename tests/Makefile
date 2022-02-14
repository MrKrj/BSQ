REDDARK	=	\033[31;1m
RED		=	\033[31;1m
GREEN	=	\033[32;1m
YEL		=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[0m

SRC		=	../src/start.c		\
			../src/bsq.c

SRC_UT	=	src/test_start.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)
RM_FILE	=	$(OBJ:.o=.gcno) $(OBJ:.o=.gcda)
RM		=	rm -f
CC		=	gcc
CFLAGS	=	-W -Wall -Wextra $(INC) -Werror --coverage
LDFLAGS	=	-lcriterion -lgcov -L../lib/ -lll -lstr -ldisp
INC		=	-I../include
NAME	=	unit_tests

all:		$(NAME)

$(NAME):	make_lib $(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@:
		@printf "\n$(BLUE)  [$(WHITE)%s$(BLUE)] → " $(NAME)
		@printf "$(WHITE)Compilation terminée. "
		@printf "$ Binaire : $(CYAN) ./%s$(WHITE)\n\n" $(NAME)

%.o:		%.c
		@$(CC) -o $(CFLAGS) -o $@ -c $<

make_lib:
		@make -C ../lib --no-print-directory

clean:
		@$(RM) $(OBJ)
		@printf "$(BLUE)\n$(WHITE)"
		@printf "$(BLUE)  [$(WHITE)%s$(BLUE)] → " $(NAME)
		@printf "$(WHITE)Suppression terminée.\n\n"

fclean:
		@$(RM) $(OBJ) $(RM_FILE)
		@$(RM) $(NAME)
		@printf "$(BLUE)\n$(WHITE)"
		@printf "$(BLUE)  [$(WHITE)%s$(BLUE)] → " $(NAME)
		@printf "$(WHITE)Suppression terminée.\n\n"

re:			fclean all

.PHONY:		all clean fclean re
