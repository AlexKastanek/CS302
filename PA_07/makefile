all: run
run: main.cpp BinaryNode.o RedBlackTree.o
	g++ -std=c++11 main.cpp BinaryNode.o RedBlackTree.o -o run
BinaryNode.o: BinaryNode.cpp
	g++ -std=c++11 -c BinaryNode.cpp
RedBlackTree.o: RedBlackTree.cpp
	g++ -std=c++11 -c RedBlackTree.cpp
clean:
	rm -rf *.o run
