##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NIBBLER_NAME =	../../lib/arcade_nibbler.so
PACMAN_NAME =	../../lib/arcade_pacman.so

CC =	g++

NIBBLER_SRC = $(wildcard nibbler/*.cpp)
PACMAN_SRC = $(wildcard pacman/*.cpp)

NIBBLER_OBJ =   $(NIBBLER_SRC:.cpp=.o)
PACMAN_OBJ =   $(PACMAN_SRC:.cpp=.o)

CXXFLAGS +=	-W -Wall -Wextra -fPIC
LDFLAGS = -shared -rdynamic -std=c++11

all:	$(NIBBLER_NAME) $(PACMAN_NAME)

$(NIBBLER_NAME):	$(NIBBLER_OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) $(NIBBLER_OBJ) -o $(NIBBLER_NAME) $(LDFLAGS)

$(PACMAN_NAME):	$(PACMAN_OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) $(PACMAN_OBJ) -o $(PACMAN_NAME) $(LDFLAGS)

clean:
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;31m Delete:\033[1m" $<
		$(RM) nibbler/*.o
		$(RM) pacman/*.o
		$(RM) nibbler/*~
		$(RM) pacman/*~
		$(RM) *~

fclean: clean
		$(RM) $(NIBBLER_NAME)
		$(RM) $(PACMAN_NAME)

re :	fclean all

.PHONY:	all clean fclean re