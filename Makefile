Stack: main.o PreconditionViolationException.o 
	g++ -std=c++11 -g -Wall main.o PreconditionViolationException.o -o Stack

main.o: main.cpp Stack.h Node.h StackInterface.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp 
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp 

clean:
	rm *.o Stack


