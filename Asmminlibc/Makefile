##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME =	libasm.so

CC =	ld

AS =	nasm

SRC =	$(wildcard src/*.asm)

OBJ =   $(SRC:.asm=.o)

ASFLAGS = 	-f elf64
CFLAGS =	-shared -fPIC

all:	$(NAME)

$(NAME):	$(OBJ)
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;35m Compiling:\033[37m" $<
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o:	%.asm
		$(AS) $(ASFLAGS) -o $@ $<

clean:
		@echo -e "\033[0;32m [OK] \033[0m       \033[0;31m Delete:\033[1m" $<
		$(RM) *.o src/*.o
		$(RM) *~ src/*~ include/*~

fclean: clean
		$(RM) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re
