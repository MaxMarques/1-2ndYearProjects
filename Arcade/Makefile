##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME =	arcade

CC =	g++

SRC =	$(wildcard src/*.cpp) $(wildcard src/core/*.cpp)

OBJ =   $(SRC:.cpp=.o)

CFLAGS =	-W -Wall -Wextra -ldl

all:	$(NAME)
		$(MAKE) -C src/library
		$(MAKE) -C src/game

$(NAME):	$(OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

graphicals:
		$(MAKE) -C src/library

games:
		$(MAKE) -C src/game

core:	$(OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;31m Delete:\033[1m" $<
		$(RM) *.o src/*.o src/core/*o
		$(RM) *~ src/*~ src/core/*~
		$(MAKE) clean -C src/library
		$(MAKE) clean -C src/game

fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C src/library
		$(MAKE) fclean -C src/game

re :	fclean all
		$(MAKE) re -C src/library
		$(MAKE) re -C src/game

.PHONY:	all clean fclean re library games core