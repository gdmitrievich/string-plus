GCC = gcc
GCCF = gcc -Wall -Wextra -Werror -std=c11
CH_CM1 = checkmk clean_mode=1
CLANG = clang-format -i
TEST_FILE_NAME = s21_test

ifeq ($(shell uname), Linux)
	TEST_LIB = -lcheck -lm -lrt -lpthread -lsubunit
	OPEN_CMD = xdg-open
else
	TEST_LIB = -lcheck -lm -lpthread
	OPEN_CMD = open
endif

all:  s21_string.a test

s21_string.a: s21_string.o
	@ ar r s21_string.a s21_string.o
	@ ranlib s21_string.a
	@ rm -f s21_string.o

s21_string.o: clang-format s21_string.c s21_string.h
	@ $(GCCF) -c s21_string.c -o s21_string.o

clang-format: s21_string.c s21_string.h
	@ cp ../materials/linters/.clang-format .
	@ $(CLANG) s21_string.c s21_string.h


test: $(TEST_FILE_NAME).c
	@ $(GCC) $(TEST_FILE_NAME).c s21_string.a -o $(TEST_FILE_NAME).out $(TEST_LIB)
	@ ./$(TEST_FILE_NAME).out

$(TEST_FILE_NAME).c: $(TEST_FILE_NAME).check
	@ $(CH_CM1) $(TEST_FILE_NAME).check > $(TEST_FILE_NAME).c
	@ cp ../materials/linters/.clang-format .
	@ $(CLANG) $(TEST_FILE_NAME).c

gcov_report: $(TEST_FILE_NAME).c
	@ $(GCC) --coverage $(TEST_FILE_NAME).c s21_string.c -o $(TEST_FILE_NAME) $(TEST_LIB)
	@ ./$(TEST_FILE_NAME)
	@ lcov -t "$(TEST_FILE_NAME)" -o $(TEST_FILE_NAME).info -c -d .
	@ genhtml -o report $(TEST_FILE_NAME).info
	@ $(OPEN_CMD) ./report/index.html

clean:
	@ rm -f $(TEST_FILE_NAME).c
	@ rm -f $(TEST_FILE_NAME).out
	@ rm -f .clang-format

	@ rm -rf report
	@ rm -f $(TEST_FILE_NAME)
	@ rm -f *.gcda
	@ rm -f *.gcno
	@ rm -f $(TEST_FILE_NAME).info

	@ rm -f s21_string.a
	@ rm -f s21_string.o

rebuild: clean all
