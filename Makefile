main: main.o
	g++ -std=c++11 -o $@ $<
main.O: main.cpp
	g++ -c $< -o $@