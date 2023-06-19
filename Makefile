##
## EPITECH PROJECT, 2022
## palyndrome
## File description:
## Makefile
##

MAINFILE	=	src/main.c			\
				src/exec_flags.c	\
				src/init.c 			\
				src/parse_arg.c	\

BINNAME		=	projTester

LIBNAME		=	lib/my/libmy.a

OBJ			=	$(MAINFILE:.c=.o)

LIB			=	-L./lib/my -lmy

INCF		=	include/

FLAGS		=	-I./$(INCF) $(LIB) -W -Wall -Wextra

all: $(BINNAME)

$(INCF):
	mkdir -p $(INCF)

$(LIBNAME):
	@make -C lib/my/ -w

$(BINNAME):	$(INCF)	$(LIBNAME)
	gcc -o $(BINNAME) $(MAINFILE) $(FLAGS)
	@if [ -f $(BINNAME) ]; then \
		echo -e "\033[92m\nFile succesfully compiled\n\033[0m" ; \
	fi

clean:
	@rm -f $(OBJ)
	@rm -f $(LIBNAME)
	@make -C lib/my/ clean
	@if [ -z "$(find . -name "*.o")" ] && [ ! -f $(LIBNAME) ]; then \
		echo -e "\033[92m\nClean succesfully done\n\033[0m" ; \
	fi

fclean: clean
	rm -f $(BINNAME)
	@if [ ! -f $(BINNAME) ]; then \
		echo -e "\033[92m\nFclean succesfully done\n\033[0m" ; \
	fi

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(BINNAME)

ftests:
	./tests/tester.sh

unit_tests:
	@make -C tests/ -w

exec_unit_tests:
	@make -C tests/ run

clean_tests:
	@make -C tests/ clean

fclean_tests:
	@make -C tests/ fclean

re_tests:
	@make -C tests/ compile_run

all_tests: unit_tests ftests

re: fclean all
