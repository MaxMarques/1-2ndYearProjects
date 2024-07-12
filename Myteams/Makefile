##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME_SERVEUR =	myteams_server
NAME_CLIENT =	myteams_cli

CC =	gcc

SRC_SERVEUR =	src/serveur/main.c	\
				src/serveur/socket_serveur.c	\
				src/serveur/serveur.c	\
				src/serveur/new_client.c	\
				src/serveur/parser.c	\
				src/serveur/my_free.c	\
				src/serveur/serveur_message.c	\
				src/serveur/linked_list.c	\
				src/serveur/cmd/logout_cmd.c	\
				src/serveur/cmd/login_cmd.c	\
				src/serveur/cmd/help_cmd.c	\
				src/serveur/cmd/quit_cmd.c	\
				src/serveur/buffer.c	\
				src/serveur/socket_rw.c	\
				src/serveur/close_client_socket.c	\
				src/serveur/my_strcomb.c	\
				src/serveur/parse_clients.c	\
				src/serveur/uuid_generator.c	\
				src/serveur/parse_data.c	\
				src/serveur/data_directory.c	\
				src/serveur/is_user_exist.c	\
				src/serveur/cmd/users_cmd.c	\
				src/serveur/cmd/use_cmd.c	\
				src/serveur/cmd/create_cmd.c	\
				src/serveur/get_users.c	\

SRC_CLIENT =	src/client/main.c	\
				src/client/socket_client.c	\
				src/client/client.c	\
				src/client/cmd/login.c	\
				src/client/cmd/logout.c	\
				src/client/cmd/users.c	\
				src/client/buffer_client.c	\

OBJ_SERVEUR =	$(SRC_SERVEUR:.c=.o)
OBJ_CLIENT =	$(SRC_CLIENT:.c=.o)

CFLAGS +=	-W -Wall -Wextra -Iinclude/ -Ilibs/myteams -L. -g -luuid
LDFLAGS	+=	-L./libs/myteams/ -lmyteams -luuid

all:	$(NAME_SERVEUR) $(NAME_CLIENT)

$(NAME_SERVEUR):	$(OBJ_SERVEUR)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) -o $(NAME_SERVEUR) $(OBJ_SERVEUR) $(LDFLAGS)

$(NAME_CLIENT):	$(OBJ_CLIENT)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LDFLAGS)

client:
		$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LDFLAGS)
serveur:
		$(CC) -o $(NAME_SERVEUR) $(OBJ_SERVEUR) $(LDFLAGS)

tests_run:
		@cd tests/ && $(MAKE)
		./tests/unit_tests
clean:
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;31m Delete:\033[1m" $<
		$(RM) *.o src/serveur/*.o src/client/*.o src/serveur/cmd/*.o src/client/cmd/*.o
		$(RM) *~ src/serveur/*~ src/client/*~ src/serveur/cmd/*~
		$(RM) include/*~
		$(RM) tests/*.gcda tests/*.gcno tests/*.o
		$(RM) src/*.gcda src/*.gcdo $(RM) src/serveur/*.gcda src/serveur/*.gcdo

fclean: clean
		$(RM) $(NAME_SERVEUR)
		$(RM) $(NAME_CLIENT)

re :	fclean all

.PHONY:	all clean tests_run fclean client serveur re