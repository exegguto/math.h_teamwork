CC=gcc
DIRECTORY=pwd
CFLAGS=-std=c11 -Wall -Werror -Wextra
TC_FLAGS=
LEAK_CHECK=
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC += -D LINUX -g
	TC_FLAGS += -lcheck -lsubunit -lm -lrt -lpthread
	LEAK_CHECK +=CK_FORK=no valgrind --trace-children=yes --track-fds=yes --leak-check=yes --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt ./test.out
endif
ifeq ($(UNAME_S),Darwin)
    CC += -D OSX
	TC_FLAGS += $(shell pkg-config --cflags check) $(shell pkg-config --libs check)
	LEAK_CHECK +=CK_FORK=no leaks -atExit -- ./test.out
endif

FLAG1=-I src
FLAG2=-c

default: all

all: clean s21_math.a test

test: s21_math.a
	$(CC) test.c s21_math.a -o test.out $(TC_FLAGS)
	./test.out

s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a

s21_math.o: s21_math.c
	$(CC) $(FLAG1) $(CFLAGS) $(FLAG2) s21_math.c -o s21_math.o

clean:
	rm -rf  *.a *.o *.out *.txt *.info *.gcno *.gcda report *.cfg

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	$(LEAK_CHECK)

gcov_report:
	$(CC) --coverage test.c s21_math.c -o test.out $(TC_FLAGS)
	./test.out
	lcov -t "test.out" -o test.info -c -d .
	genhtml -o report test.info
