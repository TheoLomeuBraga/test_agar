all:
	g++ -o ./test_agar `agar-config --cflags` ./test_agar.cpp `agar-config --libs`

