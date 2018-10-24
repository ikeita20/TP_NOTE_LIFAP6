all: executable.out

executable.out : main.o table.o produit.o

	g++ main.o table.o produit.o -o executable.out


main.o : main.cpp table.h 

	g++ -Wall -c main.cpp


table.o : table.cpp table.h produit.h

	g++ -Wall -c table.cpp

produit.o : produit.cpp produit.h 

	g++ -Wall -c produit.cpp 

clean :
	rm *.o

veryclean : clean 
	rm *.out

