G=g++ -std=c++17 -Wall -Werror -Wextra
TEST=-lgtest
COV=--coverage

all: clean gcov_report

s21_matrix_oop.a: clean
	$(G) -c *.cc
	ar rcs s21_matrix_oop.a *.o

test: clean
	$(G) $(COV) -c *.cc
	$(G) -c tests/test.cc $(TEST)
	$(G) $(COV) -o test *.o $(TEST)
	./test

gcov_report: test
	lcov -t "Tests" -o s21_matrix_oop.info -c -d .
	lcov -e s21_matrix_oop.info '*.cc' -o s21_matrix_oop.info.filtered
	genhtml -o report s21_matrix_oop.info.filtered
	open ./report/index.html

clang_check:
	clang-format --style=Google -n *.cc *.h tests/*.cc

clang_lint:
	clang-format --style=Google -i *.cc *.h tests/*.cc

leaks: test
	leaks -atExit -- ./test

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info test report *.filtered
