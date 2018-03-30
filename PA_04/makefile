all: test
test: main.cpp bubbleSort.o mergeSort.o radixSort.o
	g++ main.cpp -std=c++11 bubbleSort.o mergeSort.o radixSort.o -o test 
bubbleSort.o: bubbleSort.cpp
	g++ -c bubbleSort.cpp
mergeSort.o: mergeSort.cpp
	g++ -c mergeSort.cpp
radixSort.o: radixSort.cpp
	g++ -c radixSort.cpp
clean:
	rm -rf *.o test
