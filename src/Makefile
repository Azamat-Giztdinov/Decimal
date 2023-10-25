CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
OS := $(shell uname)

ifeq ($(OS),Linux)
FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
else
FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
endif

all: test gcov_report

test: clean s21_decimal.a
	$(CC) ./tests/*.c s21_decimal.a $(FLAGS) -o unit_test
	./unit_test

s21_decimal.a: s21_anotherfunctions.o s21_bigdecimal.o s21_bitunthion.o s21_comparison.o s21_converters.o s21_arithmetic.o s21_srtfunction.o
	ar -crs  s21_decimal.a s21_anotherfunctions.o s21_bigdecimal.o s21_bitunthion.o s21_comparison.o s21_converters.o s21_arithmetic.o s21_srtfunction.o

gcov_report: clean
	$(CC) ./tests/*.c s21_*.c $(FLAGS) -o unit_test
	./unit_test
	lcov -t "./unit_test"  -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.o *.a unit_test
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info

check:
	cp ../materials/linters/.clang-format ./
	cp ../materials/linters/.clang-format ./tests/
	clang-format -n *.c *.h
	clang-format -n ./tests/*.c ./tests/*.h
	rm -rf .clang-format
	rm -rf ./tests/.clang-format

s21_anotherfunctions.o:
	$(CC) $(CFLAGS) -c s21_anotherfunctions.c

s21_bigdecimal.o:
	$(CC) $(CFLAGS) -c s21_bigdecimal.c

s21_bitunthion.o:
	$(CC) $(CFLAGS) -c s21_bitunthion.c

s21_comparison.o:
	$(CC) $(CFLAGS) -c s21_comparison.c

s21_converters.o:
	$(CC) $(CFLAGS) -c s21_converters.c

s21_arithmetic.o:
	$(CC) $(CFLAGS) -c s21_arithmetic.c

s21_srtfunction.o:
	$(CC) $(CFLAGS) -c s21_srtfunction.c

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./unit_test

leak: test
    CK_FORK=no leaks --atExit -- ./unit_test