GCC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
CLANG = clang-format -i


all: s21_string.a

s21_string.a: s21_string.o
	ar r libs21_string.a s21_string.o

s21_string.o: clang-format s21_string.c s21_string.h
	$(GCC) $(FLAGS) -c s21_string.c -o s21_string.o

clang-format: s21_string.c s21_string.h
	cp ../materials/linters/.clang-format .
	$(CLANG) s21_string.c s21_string.h

clean:
	@ rm -f *.a
	@ rm -f *.o
	@ rm -f .clang-format

rebuild: clean all
