NAME = pushswap_checker

SRC = pushswap_checker.hs

all: $(NAME)

$(NAME): $(SRC)
	ghc $(NAME)

clean:
	$(RM) -rf *.hi *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all