all: FlightMap
FlightMap: main.cpp FlightMap.v1.o FlightMap.v2.o stack.o
	g++ main.cpp stack.o FlightMap.v1.o FlightMap.v2.o -o FlightMap
FlightMap.v1.o: FlightMap.v1.cpp
	g++ -c FlightMap.v1.cpp
FlightMap.v2.o: FlightMap.v2.cpp
	g++ -c FlightMap.v2.cpp
stack.o: stack.cpp
	g++ -c stack.cpp
clean:
	rm -rf *.o FlightMap
