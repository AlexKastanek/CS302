// Class Header File Information //////////////////////////////////////////////
/**
  * @file BinarySearchTree.h
  *
  * @brief Definition file for BinarySearchTree class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the BinarySearchTree class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of BinarySearchTree class
  *
  * @note None
  *
  */

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <fstream>
#include <cstddef>
#include "BinaryNode.h"

class BinarySearchTree
{
	public:
		BinarySearchTree();
		BinarySearchTree(int);
		~BinarySearchTree();

		int getHeightHelper(BinaryNode*) const;
		int getNumberOfNodesHelper(BinaryNode*) const;
		BinaryNode* placeNode(BinaryNode*, BinaryNode*);
		BinaryNode* removeValue(BinaryNode*, int, bool&);
		BinaryNode* removeNode(BinaryNode*);
		BinaryNode* removeLeftmostNode(BinaryNode*, int&);
		void destroyTree(BinaryNode*);
		void preorder(void visit(int&), BinaryNode*) const;
		void inorder(void visit(int&), BinaryNode*) const;
		void postorder(void visit(int&), BinaryNode*) const;
		
		bool isEmpty() const;
		int getHeight() const;
		int getNumberOfNodes() const;
		int getRootData() const;
		BinaryNode* getRootNode() const;
		void setRootData(int);
		bool add(int);
		bool remove(int);
		void clear();

		void preorderTraverse(void visit(int&)) const;
		void inorderTraverse(void visit(int&)) const;
		void postorderTraverse(void visit(int&)) const;

	private:
		BinaryNode* rootPtr;


};

#endif
