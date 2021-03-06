#ifndef BINARY_NODE
#define BINARY_NODE

#include <iostream>
#include <fstream>
#include <cstddef>

using namespace std;

class BinaryNode
{

	public:
		BinaryNode();
		BinaryNode(int);
		BinaryNode(int, BinaryNode*, BinaryNode*);

		void setItem(int);
		int getItem() const;

		bool isLeaf() const;
		int getNumOfChildren() const;

		BinaryNode* getLeftChildPtr() const;
		BinaryNode* getRightChildPtr() const;

		void setLeftChildPtr(BinaryNode*);
		void setRightChildPtr(BinaryNode*);

	private:
		int data;
		BinaryNode* leftChildPtr;
		BinaryNode* rightChildPtr;

};

#endif
