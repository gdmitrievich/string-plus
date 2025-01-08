GCC = gcc
GCCF = gcc -Wall -Wextra -Werror -std=c11
CH_CM1 = checkmk clean_mode=1
CLANG = clang-format -i
FILE_NAME = first_test

ifeq ($(shell uname), Linux)
	TEST_LIB = -lcheck -lm -lrt -lpthread -lsubunit
	OPEN_CMD = xdg-open
else
	TEST_LIB = -lcheck -lm -lpthread
	OPEN_CMD = open
endif


all: test

test: $(FILE_NAME).c
	@ $(GCCF) $(FILE_NAME).c -o $(FILE_NAME).out $(TEST_LIB)
	@ ./$(FILE_NAME).out

$(FILE_NAME).c: $(FILE_NAME).check
	@ $(CH_CM1) $(FILE_NAME).check > $(FILE_NAME).c
	@ cp ../materials/linters/.clang-format .
	@ $(CLANG) $(FILE_NAME).c

gcov_report: $(FILE_NAME).c
	@ $(GCC) --coverage $(FILE_NAME).c -o $(FILE_NAME) $(TEST_LIB)
	./$(FILE_NAME)
	lcov -t "$(FILE_NAME)" -o $(FILE_NAME).info -c -d .
	genhtml -o report $(FILE_NAME).info
	$(OPEN_CMD) ./report/index.html

clean:
	@ rm -f $(FILE_NAME).c
	@ rm -f $(FILE_NAME).out
	@ rm -f .clang-format

	@ rm -rf report
	@ rm -f $(FILE_NAME)
	@ rm -f $(FILE_NAME).gcda
	@ rm -f $(FILE_NAME).gcno
	@ rm -f $(FILE_NAME).info


rebuild: clean all
