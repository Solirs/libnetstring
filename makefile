build:
	gcc tests.c libnetstring.h -o libnetstring_test

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./libnetstring_test
