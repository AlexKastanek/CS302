CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

PA01 : PA01.o LinkedList.o Node.o PrecondViolatedExcept.o
	$(CC) $(LFLAGS) -std=c++11 PrecondViolatedExcept.o Node.o LinkedList.o PA01.o -o PA01

PA01.o : LinkedList.cpp PA01.cpp
	$(CC) $(CFLAGS) -std=c++11 PA01.cpp

LinkedList.gch : LinkedList.h ListInterface.h PrecondViolatedExcept.cpp
	$(CC) $(CFLAGS) -std=c++11 LinkedList.h
	
PrecondViolatedExcep.o : PrecondViolatedExcept.cpp PrecondViolatedExcept.h
	$(CC) $(CFLAGS) -std=c++11 PrecondViolatedExcept.cpp
	
Node.gch : Node.h
	$(CC) $(CFLAGS) -std=c++11 Node.h

clean:
	\rm *.o PA01
