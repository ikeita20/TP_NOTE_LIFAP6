all: executable.out

executable.out : main.o table.o produit.o

	g++ -std=c++11 main.o table.o produit.o -o executable.out


main.o : main.cpp table.h

	g++ -std=c++11 -Wall -c main.cpp


table.o : table.cpp table.h produit.h

	g++  -std=c++11 -Wall -c table.cpp

produit.o : produit.cpp produit.h

	g++ -std=c++11 -Wall -c produit.cpp

clean :
	rm *.o

veryclean : clean
	rm *.out
