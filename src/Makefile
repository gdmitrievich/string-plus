CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
CH_CM1 = checkmk clean_mode=1
CLANG = clang-format -i
TEST_FILE_NAME = s21_test
SOURCES = s21_string.c s21_string_extra.c common.c p_format_args.c s21_sprintf.c

ifeq ($(shell uname), Linux)
	TEST_LIB = -lcheck -lm -lrt -lpthread -lsubunit
	OPEN_CMD = xdg-open
else
	TEST_LIB = -lcheck -lm -lpthread
	OPEN_CMD = open
endif

all:  clean s21_string.a test

s21_string.a: s21_string.o
	@ ar r s21_string.a *.o
	@ ranlib s21_string.a
	@ rm -f s21_string.o

s21_string.o:
	@ $(CC) $(CFLAGS) -c $(SOURCES)

clang-format: 
	@ cp ../materials/linters/.clang-format .
	@ $(CLANG) *.c *.h


test: $(TEST_FILE_NAME).c
	@ $(CC) $(CFLAGS) $(TEST_FILE_NAME).c s21_string.a -o $(TEST_FILE_NAME).out $(TEST_LIB)
	@ ./$(TEST_FILE_NAME).out

$(TEST_FILE_NAME).c: $(TEST_FILE_NAME).check
	@ $(CH_CM1) $(TEST_FILE_NAME).check > $(TEST_FILE_NAME).c
	@ cp ../materials/linters/.clang-format .
	@ $(CLANG) $(TEST_FILE_NAME).c

gcov_report: $(TEST_FILE_NAME).c
	@ $(CC) --coverage $(TEST_FILE_NAME).c $(SOURCES)  ../tests/s21_trim_tests.c -o $(TEST_FILE_NAME) $(TEST_LIB)
	@ ./$(TEST_FILE_NAME)
	@ lcov -t "$(TEST_FILE_NAME)" -o $(TEST_FILE_NAME).info -c -d .
	@ genhtml -o report $(TEST_FILE_NAME).info
	@ $(OPEN_CMD) ./report/index.html

gcov_report_trim: $(SOURCES)
	@ $(CC) --coverage $(SOURCES) ../tests/s21_trim_tests.c -o ../tests/s21_trim_tests $(TEST_LIB)
	@ ./../tests/s21_trim_tests
	@ lcov -t "../tests/s21_trim_tests" -o ../tests/s21_trim_tests.info -c -d .
	@ genhtml -o report ../tests/s21_trim_tests.info
	@ $(OPEN_CMD) ./report/index.html

gcov_report_sprintf: $(SOURCES)
	@ $(CC) --coverage $(SOURCES) ../tests/s21_sprintf_tests.c -o ../tests/s21_sprintf_tests $(TEST_LIB)
	@ ./../tests/s21_sprintf_tests
	@ lcov -t "../tests/s21_sprintf_tests" -o ../tests/s21_sprintf_tests.info -c -d .
	@ genhtml -o report ../tests/s21_sprintf_tests.info
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
	@ rm -f *.o

	@ rm -f ../tests/*.gcda
	@ rm -f ../tests/*.gcno

rebuild: clean all
