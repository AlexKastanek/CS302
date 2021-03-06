// Class Header File Information //////////////////////////////////////////////
/**
  * @file RedBlackTree.h
  *
  * @brief Definition file for RedBlackTree class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the RedBlackTree class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of RedBlackTree class
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

class RedBlackTree
{
	public:
		RedBlackTree();
		RedBlackTree(int);
		~RedBlackTree();

		int getHeightHelper(BinaryNode*) const;
		void destroyTree(BinaryNode*);
		void preorder(void visit(int&), BinaryNode*) const;
		void inorder(void visit(int&), BinaryNode*) const;
		void postorder(void visit(int&), BinaryNode*) const;
		
		bool isEmpty() const;
		int getHeight() const;
		int getRootData() const;
		BinaryNode* getRootNode() const;
		void setRootData(int);
		void insert(int);
		void insertFix(BinaryNode*);
		void leftRotate(BinaryNode*);
		void rightRotate(BinaryNode*);
		void clear();

		void preorderTraverse(void visit(int&)) const;
		void inorderTraverse(void visit(int&)) const;
		void postorderTraverse(void visit(int&)) const;

	private:
		BinaryNode* rootPtr;


};

#endif
