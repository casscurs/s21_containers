CC = g++ -std=c++17
CFLAGS = -Wall -Wextra -Werror -lstdc++ -lm
TEST_FLAGS = -lgtest -pthread
TEST_FILES = ./tests/test_s21_*.cc

all: test

test: clean  
	$(CC) $(CFLAGS) $(TEST_FILES) -o test $(TEST_FLAGS)
	./test

clean:
	rm -rf test

valgrind: test
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./test
