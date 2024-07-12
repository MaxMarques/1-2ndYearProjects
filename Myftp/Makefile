##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME =	myftp

CC =	gcc

SRC =	$(wildcard *.c) $(wildcard src/*.c) $(wildcard src/cmd/*.c)

OBJ =   $(SRC:.c=.o)

CFLAGS +=	-W -Wall -Wextra -Iinclude/ -L. -g

all:	$(NAME)

$(NAME):	$(OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;31m Delete:\033[1m" $<
		$(RM) *.o src/*.o src/cmd/*.o
		$(RM) *~ src/*~ src/cmd/*~
		$(RM) include/*~

fclean: clean
		$(RM) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re
