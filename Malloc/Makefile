##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME =	libmy_malloc.so

CC =	gcc

SRC =	$(wildcard src/*.c)

OBJ =   $(SRC:.c=.o)

CFLAGS +=	-W -Wall -Wextra -Werror -fPIC -Iinclude -L.

all:	$(NAME)

$(NAME):	$(OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(LD) -shared -o $(NAME) $(OBJ)

clean:
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;31m Delete:\033[1m" $<
		$(RM) *.o src/*.o
		$(RM) *~ src/*~

fclean: clean
		$(RM) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re