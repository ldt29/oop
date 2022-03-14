main: main.o product.o sum.o
	g++ $^ -o $@ -g
%.o: %.cpp functions.h
	g++ -c $< -o $@

debug: 
	g++ -D DEBUG -c sum.cpp -o sum.o
	g++ -D DEBUG -c product.cpp -o product.o
	make
clean:
	rm -f *.o main
