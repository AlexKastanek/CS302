all: test
test: main.cpp BinaryNode.o BinarySearchTree.o
	g++ -std=c++11 main.cpp BinaryNode.o BinarySearchTree.o -o test
BinaryNode.o: BinaryNode.cpp
	g++ -std=c++11 -c BinaryNode.cpp
BinarySearchTree.o: BinarySearchTree.cpp
	g++ -std=c++11 -c BinarySearchTree.cpp
clean:
	rm -rf *.o test
