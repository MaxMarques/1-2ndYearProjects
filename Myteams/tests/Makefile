##
## EPITECH PROJECT, 2019
## unit_tests
## File description:
## unit_tests
##

NAME	= unit_tests

CC	= gcc

RM	= rm -f

SRCS	= $(wildcard ../tests/*.c) $(wildcard ../src/serveur/my_strcomb.c) $(wildcard ../src/serveur/parse_data.c) $(wildcard ../src/serveur/uuid_generator.c)

OBJS	= $(SRCS:.c=.o)

RUN = ./unit_tests

CFLAGS = -I ../include/ -g --coverage -I../tests/include
CFLAGS += -O2 -pipe -Wall -Wextra -Wshadow -Wuninitialized -Wformat-security -luuid
LDFLAGS = -lcriterion --coverage -luuid

all: $(NAME) run

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) *.gc*

fclean: clean
	$(RM) $(NAME)

re: fclean all

run : $(RUN)

.PHONY: all clean fclean re