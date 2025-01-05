GCCF = gcc -Wall -Wextra -Werror -std=c11
CH_CM1 = checkmk clean_mode=1
CLANG = clang-format -i
FILE_NAME = first_test

ifeq ($(shell uname), Linux)
	TEST_LIB = -lcheck -lm -lrt -lpthread -lsubunit
else
	TEST_LIB = -lcheck -lm -lpthread
endif


all: test

test: $(FILE_NAME).c
	@ $(GCCF) $(FILE_NAME).c -o $(FILE_NAME).out $(TEST_LIB)
	@ ./$(FILE_NAME).out

$(FILE_NAME).c: $(FILE_NAME).check
	@ $(CH_CM1) $(FILE_NAME).check > $(FILE_NAME).c
	@ cp ../materials/linters/.clang-format .
	@ $(CLANG) $(FILE_NAME).c

clean:
	@ rm -f $(FILE_NAME).c
	@ rm -f $(FILE_NAME).out
	@ rm -f .clang-format

rebuild: clean all
