cc = gcc
compilation-flags = -Wall -Werror -Wextra

lib-name = s21_matrix.a
lib-header = ./s21_matrix.h

system := $(shell uname -s)

debug:
	$(cc) $(compilation-flags) -c ./creation_and_deletion/*.c ./comparison/*.c ./helpers/*.c ./arithmetic/*.c ./other_operations/*.c
	ar rcs debug.a ./*.o
	ranlib debug.a
	gcc test.c debug.a
	./a.out

clean:
	rm -rf *.gcno *.html report
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf $(TESTS) *.a
	rm -rf *.info
	rm -rf *.o
	rm -rf *.out
	rm -rf *.dSYM
