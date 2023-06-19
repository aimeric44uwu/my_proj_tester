##
## EPITECH PROJECT, 2022
## my_fast_a_tool
## File description:
## Makefile
##

BINNAME		=	unit_tests

MAIN 		=	unitary_tests.c

INCF		=	include/

LIB			=	-L../lib/my -lmy

FLAGS		=	-I../$(INCF) -lcriterion --coverage -w

all: $(BINNAME)

$(BINNAME):
	gcc -o $(BINNAME) $(MAIN) $(LIB) $(FLAGS)
	@if [ -f $(BINNAME) ]; then \
		echo -e "\033[92m\nFile succesfully compiled\n\033[0m" ; \
	fi

clean:
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f *.o
	@rm -f *.gcov

run: $(BINNAME)
	./$(BINNAME)

fclean: clean
	rm -f $(BINNAME)
	@if [ ! -f $(BINNAME) ]; then \
		echo -e "\033[92m\nFclean succesfully done\n\033[0m" ; \
	fi

compile_run:
	@rm -f $(BINNAME)
	@make
	@make run
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f *.o
	@rm -f *.gcov
	@rm -f $(BINNAME)

re: fclean all