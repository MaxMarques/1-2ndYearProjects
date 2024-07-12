##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SFML_NAME =	../../lib/arcade_sfml.so
NCURSES_NAME = ../../lib/arcade_ncurses.so
SDL_NAME = ../../lib/arcade_sdl2.so

CC =	g++

SFML_SRC =	$(wildcard SFML/*.cpp)
NCURSES_SRC =	$(wildcard NCURSES/*.cpp)
SDL_SRC =	$(wildcard SDL/*.cpp)

SFML_OBJ =   $(SFML_SRC:.cpp=.o)
NCURSES_OBJ =	$(NCURSES_SRC:.cpp=.o)
SDL_OBJ =	$(SDL_SRC:.cpp=.o)

CXXFLAGS +=	-W -Wall -Wextra -fPIC -g
LDFLAGS += -shared -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -rdynamic -std=c++11
CFLAGS += -shared -lncurses -rdynamic -std=c++11
CFLAGS_SDL += -shared -lSDL2 -lSDL2_ttf -lSDL2_image -rdynamic -std=c++11

all:	$(SFML_NAME) $(NCURSES_NAME) $(SDL_NAME)

$(SFML_NAME):	$(SFML_OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) $(SFML_OBJ) -o $(SFML_NAME) $(LDFLAGS)

$(NCURSES_NAME):	$(NCURSES_OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) $(NCURSES_OBJ) -o $(NCURSES_NAME) $(CFLAGS)

$(SDL_NAME):	$(SDL_OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) $(SDL_OBJ) -o $(SDL_NAME) $(CFLAGS_SDL)

clean:
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;31m Delete:\033[1m" $<
		$(RM) SFML/*.o
		$(RM) NCURSES/*.o
		$(RM) SDL/*.o
		$(RM) SFML/*~
		$(RM) NCURSES/*~
		$(RM) SDL/*~
		$(RM) *~

fclean: clean
		$(RM) $(SFML_NAME)
		$(RM) $(NCURSES_NAME)
		$(RM) $(SDL_NAME)

re :	fclean all

.PHONY:	all clean fclean re
