SRC	=	str.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

LIB	=	libstr.a

AR	=	ar rc $(LIB) *.o

RM	= 	rm -f

NAME	=	str

all: 		$(LIB)
		@:

$(LIB): 	$(OBJ)
		@$(AR)
		@mkdir -p ../../include/
		@cp str.h ../../include/
		@cp $(LIB) ../
		@:
		@printf "\t$(YEL)  [$(WHITE)%s$(YEL)]\n" $(NAME)

%.o:	%.c
		@$(CC) -o $@ -c $<

clean:
		@$(RM) $(OBJ)

fclean: 	clean
		@$(RM) $(LIB) ../$(LIB)

re: fclean all

.PHONY: all clean fclean re