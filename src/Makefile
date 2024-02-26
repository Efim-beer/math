CC=gcc
CFLAGS=-c
LDFLAGS=  #-Wall -Wextra -Werror
LIBS = -lcheck
SOURCES = s21_math.c
OBJECTS = $(SOURCES:.c=.o)

TEST_SOURCE = test.c
TEST_OBJECTS = $(TEST_SOURCE:.c=.o)

all: s21_math.a test gcov_report

objects:
	$(CC) $(CFLAGS) s21_math.c -o s21_math.o

	

s21_math.a: objects
	ar rcs s21_math.a $(OBJECTS)
	ranlib $@
	rm -rf $(OBJECTS)

test: $(TEST_OBJECTS) s21_math.a
	$(CC) -o s21_test s21_math.a $(TEST_OBJECTS) $(LIBS)
	./s21_test

gcov_report:
	$(CC) --coverage $(SOURCES) $(TEST_SOURCE) -o s21_report $(LIBS)
	./s21_report
	lcov -t "qwerty" -o s21_report.info -c -d .
	genhtml -o report s21_report.info
	open ./report/index.html

clean:
	rm -rf *.o report ../build/* *.out s21_test s21_report* *.gc* s21_math.a

rebuild: clean all

cpplint:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

leaks:
	CK_FORK=no leaks --atExit -- ./s21_test
