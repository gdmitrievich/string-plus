CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
CH_CM1 = checkmk clean_mode=1
CLANG = clang-format -i
SOURCES = s21_string.c s21_string_extra.c common.c p_format_args.c s21_sprintf.c
TEST_S21_STRING_FILE_NAME = ../tests/s21_string_tests
TEST_S21_SPRINTF_FILE_NAME = ../tests/s21_sprintf_tests
TEST_S21_TRIM_FILE_NAME = ../tests/s21_trim_tests
TEST_S21_GENERAL = ../tests/s21_gen_tests

ifeq ($(shell uname), Linux)
	TEST_LIB = -lcheck -lm -lrt -lpthread -lsubunit
	OPEN_CMD = xdg-open
else
	TEST_LIB = -lcheck -lm -lpthread
	OPEN_CMD = open
endif

all: clang-format s21_string.a

s21_string.a: s21_string.o
	@ ar r s21_string.a *.o
	@ ranlib s21_string.a
	@ rm -f s21_string.o

s21_string.o:
	@ $(CC) $(CFLAGS) -c $(SOURCES)

clang-format: 
	@ cp ../materials/linters/.clang-format .
	@ cp ../materials/linters/.clang-format ../tests/.
	@ $(CLANG) *.c *.h
	@ $(CLANG) ../tests/*.c

test: $(TEST_S21_STRING_FILE_NAME).c clang-format s21_string.a 
	@ $(CC) $(CFLAGS) $(TEST_S21_STRING_FILE_NAME).c s21_string.a -o $(TEST_S21_STRING_FILE_NAME).out $(TEST_LIB)
	@ ./$(TEST_S21_STRING_FILE_NAME).out	
	@ $(CC) $(CFLAGS) $(TEST_S21_TRIM_FILE_NAME).c s21_string.a -o $(TEST_S21_TRIM_FILE_NAME).out $(TEST_LIB)
	@ ./$(TEST_S21_TRIM_FILE_NAME).out	
	@ $(CC) $(CFLAGS) $(TEST_S21_SPRINTF_FILE_NAME).c s21_string.a -o $(TEST_S21_SPRINTF_FILE_NAME).out $(TEST_LIB)
	@ ./$(TEST_S21_SPRINTF_FILE_NAME).out

$(TEST_S21_STRING_FILE_NAME).c: $(TEST_S21_STRING_FILE_NAME).check
	@ $(CH_CM1) $(TEST_S21_STRING_FILE_NAME).check > $(TEST_S21_STRING_FILE_NAME).c
	
gcov_report: $(SOURCES) test
	@ $(CC) $(CFLAGS) --coverage $(SOURCES) $(TEST_S21_TRIM_FILE_NAME).c -o $(TEST_S21_TRIM_FILE_NAME) $(TEST_LIB)
	@ $(CC) $(CFLAGS) --coverage $(SOURCES) $(TEST_S21_STRING_FILE_NAME).c -o $(TEST_S21_STRING_FILE_NAME) $(TEST_LIB)
	@ $(CC) $(CFLAGS) --coverage $(SOURCES) $(TEST_S21_SPRINTF_FILE_NAME).c -o $(TEST_S21_SPRINTF_FILE_NAME) $(TEST_LIB)
	@ ./$(TEST_S21_TRIM_FILE_NAME)
	@ ./$(TEST_S21_STRING_FILE_NAME)
	@ ./$(TEST_S21_SPRINTF_FILE_NAME)
	@ lcov -t $(TEST_S21_TRIM_FILE_NAME) -t $(TEST_S21_STRING_FILE_NAME) -t $(TEST_S21_SPRINTF_FILE_NAME) -o $(TEST_S21_GENERAL).info -c -d ../tests/.
	@ genhtml -o report $(TEST_S21_GENERAL).info
	@ $(OPEN_CMD) ./report/index.html

clean:
	@ rm -f $(TEST_S21_STRING_FILE_NAME)
	@ rm -f $(TEST_S21_STRING_FILE_NAME).c
	@ rm -f $(TEST_S21_STRING_FILE_NAME).out
	@ rm -f $(TEST_S21_SPRINTF_FILE_NAME)
	@ rm -f $(TEST_S21_SPRINTF_FILE_NAME).out
	@ rm -f $(TEST_S21_TRIM_FILE_NAME)
	@ rm -f $(TEST_S21_TRIM_FILE_NAME).out
	@ rm -f ../tests/*.gcda
	@ rm -f ../tests/*.gcno
	@ rm -f ../tests/*.info
	@ rm -f s21_string.a
	@ rm -f *.o
	@ rm -f .clang-format
	@ rm -f ../tests/.clang-format
	@ rm -rf report

rebuild: clean all
