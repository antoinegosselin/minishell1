##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/env.c \
		src/setenv.c \
		src/unsetenv.c \
		src/get_next_line.c \
		src/my_funcs.c \
		src/cd.c \
		src/verif.c \
		src/str_valid.c \
		src/exec.c \
		src/free.c \
		src/error.c

NAME	=	mysh

OBJ	=	$(SRC:.c=.o)

LIB_PATH	=	./lib/my/

LIB_NAME	=	my

TEST_PATH 	= 	./tests/

CFLAGS	=	-W -Wall -I include/

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(OBJ) -L$(LIB_PATH) -l$(LIB_NAME) $(CFLAGS)

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB_PATH)libmy.a
	rm -f unit_test*

re:	fclean all

tests_run: 
	