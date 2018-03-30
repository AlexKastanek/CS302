// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file RedBlackTree.cpp
  *
  * @brief Implementation file for RedBlackTree class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the RedBlackTree class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of RedBlackTree class
  *
  * @note Requires RedBlackTree.h
  *
  * @note None
  *
  */

#include "RedBlackTree.h"

/**
  * @brief Constructor for class RedBlackTree
  *
  * @details Able to construct a RedBlackTree object
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
RedBlackTree::RedBlackTree()
{

	rootPtr = nullptr;

}

/**
  * @brief Constructor for class RedBlackTree
  *
  * @details Able to construct a RedBlackTree object with given parameters
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param a - rootPtr will contain this value as an item
  *
  * @exception None
  *
  * @note: None
  */
RedBlackTree::RedBlackTree(int a)
{

	rootPtr = new BinaryNode(a);

}

/**
  * @brief Destructor for class RedBlackTree
  *
  * @details Able to destruct a RedBlackTree object
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
RedBlackTree::~RedBlackTree()
{

	destroyTree(rootPtr);

}

/**
  * @brief Gets the height of the tree
  *
  * @details Recursively gets the height of the tree
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Returns 0 if there is no node, returns a 1 + the max between a
  *		 recursive call to the left side of the subtree and a recursive call to
  *		 the right side of the subtree. This will eventually get you how many
  *		 layers the tree has in total, which is the height of the tree
  *
  * @param subTreePtr - used as the root of the subTree, will call its left
  *		   side or right side depending on which one has more layers
  *
  * @exception None
  *
  * @note: None
  */
int RedBlackTree::getHeightHelper(BinaryNode* subTreePtr) const
{

	if (subTreePtr == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
	}

}

/**
  * @brief Destroys the tree
  *
  * @details Recursively destroys the tree from the bottom up
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Recursively calls destroyTree until the bottom of it is reached, then
  *		 begins to delete the nodes from the bottom up and set them to nullptr
  *
  * @param subTreePtr - the node that will be deleted after the bottom-most
  *					    nodes are
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::destroyTree(BinaryNode* subTreePtr)
{

	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
		subTreePtr = nullptr;
	}

}

/**
  * @brief Traverses the tree using preorder
  *
  * @details Traverses the tree recursively, calling visit before it traverses
  *			 the rest of the tree
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Gets the item in treePtr and calls visit using that item in the
  *		 correct order
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::preorder(void visit(int&), BinaryNode* treePtr) const
{

	if (treePtr != nullptr)
	{
		int item = treePtr->getItem();
		visit(item);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	}

}

/**
  * @brief Traverses the tree using inorder
  *
  * @details Traverses the tree recursively, calling visit after it traverses
  *			 the left side of the tree and before it traverses the right side
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Gets the item in treePtr and calls visit using that item in the
  *		 correct order
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::inorder(void visit(int&), BinaryNode* treePtr) const
{

	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		int item = treePtr->getItem();
		visit(item);
		inorder(visit, treePtr->getRightChildPtr());
	}

}

/**
  * @brief Traverses the tree using postorder
  *
  * @details Traverses the tree recursively, calling visit after it traverses
  *			 the rest of the tree
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Gets the item in treePtr and calls visit using that item in the
  *		 correct order
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::postorder(void visit(int&), BinaryNode* treePtr) const
{

	if (treePtr != nullptr)
	{
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		int item = treePtr->getItem();
		visit(item);
	}

}

/**
  * @brief Checks if tree is empty
  *
  * @details Returns true if height is 0 and false if it's not
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
bool RedBlackTree::isEmpty() const
{

	if (getHeight() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/**
  * @brief Calls recursive getHeightHelper function
  *
  * @details Calls getHeightHelper function passing the rootPtr to it as a
  *			 starting node
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
int RedBlackTree::getHeight() const
{

	return getHeightHelper(rootPtr);

}

/**
  * @brief gets the data stored in rootPtr
  *
  * @details returns the data being stored in rootPtr
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
int RedBlackTree::getRootData() const
{

	return rootPtr->getItem();

}

/**
  * @brief Returns rootPtr
  *
  * @details None
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
BinaryNode* RedBlackTree::getRootNode() const
{

	return rootPtr;

}

/**
  * @brief Sets the data stored in rootPtr to the parameter
  *
  * @details None
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param data - rootPtr's item gets set to this integer
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::setRootData(int data)
{

	rootPtr->setItem(data);

}

/**
  * @brief Inserts a new node into the red black tree
  *
  * @details Inserts a new node with specified data into the red black tree
  *			 using a nonrecursive algorithm
  *
  * @pre newNodePtr is allocated with newData
  *
  * @post newNodePtr is inserted into the red black
  *
  * @par Algorithm
  *		 Node pointers y and x traverse the tree using newData to correctly
  *		 decide which branch to take until the correct branch is null. y acts
  *		 as the parent and x acts as the child throughout the algorithm. Once
  *		 the correct place is found, y becomes newNodePtr's parent and then
  *		 depending on what value newData is, then newNodePtr becomes y's right
  *		 or left child.
  *
  * @param newData is the data that will be the new node's item
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::insert(int newData)
{

	BinaryNode* y = nullptr;
	BinaryNode* x = rootPtr;

	BinaryNode* newNodePtr = new BinaryNode(newData);
	newNodePtr->setColor(RED);

	if (rootPtr == nullptr)
	{
		rootPtr = newNodePtr;
		newNodePtr->setParent(nullptr);
		//cout << "new node " << newNodePtr->getItem() << " is root" << endl;
	}
	else
	{
		while (x != nullptr)
		{
			y = x;
			if (newNodePtr->getItem() < x->getItem())
			{
				x = x->getLeftChildPtr();
			}
			else
			{
				x = x->getRightChildPtr();
			}
		}
		newNodePtr->setParent(y);
		if (y->getItem() < newNodePtr->getItem())
		{
			y->setRightChildPtr(newNodePtr);
			//cout << "newNode " << newNodePtr->getItem() << " is right child" << endl;
		}
		else
		{
			y->setLeftChildPtr(newNodePtr);
			//cout << "newNode " << newNodePtr->getItem() << " is left child" << endl;
		}
	}

	insertFix(newNodePtr);

}

/**
  * @brief rebuilds the red black tree based on the new input
  *
  * @details rebuilds the red black tree based on the new input and follows the
  * 		 specifications that a red black tree must have
  *
  * @pre uncle
  *		 gets the new node's left or right uncle, depending on where the new
  *		 node currently is placed
  *
  *	@pre grandparent
  *		 gets the new node's parent's parent
  *
  * @post uncle and grandparent are set to black or red depending on the rest
  *		  of the tree
  *
  * @par Algorithm
  *		 First, checks if the new node, z, is the root pointer. Sets to black
  *		 if it is and returns, nothing else needs to be done. Else checks if z
  *		 is equal to null, its parent is equal to null, its grandparent is
  *		 equal to null, or if its parent's color is equal to black. If any of
  *		 those are true, nothing needs to be done. If they are all false, then
  *		 the loop begins. First the loop decides what side the uncle is on
  *		 based on whether z's parent is a right or left child. Then the loop
  *		 checks if the uncle is red (and !null) and if it is, then it simply
  *		 sets the parent and uncle to black, and the grandparent to red, then
  *		 it sets z to the grandparent so the loop can continue if it has to,
  *		 this is CASE 1. If the uncle is not red, then it checks if z is a
  *		 right or left child. If it is in the correct position then the subtree
  *		 gets rotated around z's parent, CASE 2, and then the subtree gets
  *		 rotated around the grandparent and z's parent is set to black and z's
  *		 grandparent is set to red, CASE 3, otherwise it's just case 3. The end
  *		 of the algorithm is just the root being set to black just in case it
  *		 got changed.
  *
  * @param z, the node that's being inserted
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::insertFix(BinaryNode* z)
{

	//cout << "begin insert fix" << endl;
	BinaryNode *uncle, *grandparent;
	if (rootPtr == z)
	{
		//cout << "z is root" << endl;
		z->setColor(BLACK);
		return;
	}

	while (z != nullptr && z->getParent() != nullptr && (z->getParent())->getParent() != nullptr && (z->getParent())->getColor() != BLACK)
	{
		//cout << "begin loop" << endl;
		grandparent = (z->getParent())->getParent();
		if(grandparent->getLeftChildPtr() == z->getParent())
		{
			//cout << "setting uncle to right" << endl;
			uncle = grandparent->getRightChildPtr();
			if (uncle != nullptr && uncle->getColor() == RED)
			{
				//uncle = grandparent->getRightChildPtr();
				//cout << "case 1" << endl;
				//CASE 1
				(z->getParent())->setColor(BLACK);
				uncle->setColor(BLACK);
				grandparent->setColor(RED);
				z = grandparent;
			}
			else
			{
				if ((z->getParent())->getRightChildPtr() == z)
				{
					//cout << "case 2" << endl;
					//CASE 2
					z = z->getParent();
					leftRotate(z);
				}
				//cout << "case 3" << endl;
				//CASE 3
				(z->getParent())->setColor(BLACK);
				grandparent->setColor(RED);
				rightRotate(grandparent);
			}
		}
		else
		{
			//cout << "setting uncle to left" << endl;
			uncle = grandparent->getLeftChildPtr();
			if (uncle != nullptr && uncle->getColor() == RED)
			{
				//cout << "case 1" << endl;
				//uncle = grandparent->getLeftChildPtr();
				(z->getParent())->setColor(BLACK);
				uncle->setColor(BLACK);
				grandparent->setColor(RED);
				z = grandparent;
			}
			else
			{
				if((z->getParent())->getLeftChildPtr() == z)
				{
					//cout << "case 2" << endl;
					z = z->getParent();
					rightRotate(z);
				}
				//cout << "case 3" << endl;
				(z->getParent())->setColor(BLACK);
				grandparent->setColor(RED);
				leftRotate(grandparent);
			}
		}
		rootPtr->setColor(BLACK);
	}

}

/**
  * @brief Rotates subTree to the left
  *
  * @details Rotates subTree to the left around pivot x
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 y gets x's right child. If y's left child is not equal to null, then
  *		 y's left child becomes x's parent. y's parent then becomes x's parent.
  *		 If x's parent is equal to null, then x is at the root, so y gets the
  *		 rootPtr. Otherwise if x is on the left then it gets y's left child and
  *		 if it's on the right then it gets y's right child. Finally, x becomes
  *		 y's left child and y becomes x's parent.
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::leftRotate(BinaryNode* x)
{

	if (x->getRightChildPtr() == nullptr)
	{
		return;
	}
	else
	{
		BinaryNode* y = x->getRightChildPtr();
		x->setRightChildPtr(y->getLeftChildPtr());
		if (y->getLeftChildPtr() != nullptr)
		{
			//x->setRightChildPtr(y->getLeftChildPtr());
			(y->getLeftChildPtr())->setParent(x);
			//x->setParent(y);
		}
		/*else
		{
			x->setRightChildPtr(nullptr);
		}*/
		y->setParent(x->getParent());
		/*if (x->getParent() != nullptr)
		{
			y->setParent(x->getParent());
		}*/
		if (x->getParent() == nullptr)
		{
			rootPtr = y;
		}
		else
		{
			if (x == (x->getParent())->getLeftChildPtr())
			{
				(x->getParent())->setLeftChildPtr(y);
			}
			else
			{
				(x->getParent())->setRightChildPtr(y);
			}
		}
		y->setLeftChildPtr(x);
		x->setParent(y);
	}

}

/**
  * @brief Rotates subTree to the right
  *
  * @details Rotates subTree to the right around pivot x
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 y gets x's left child. If y's right child is not equal to null, then
  *		 y's right child becomes x's parent. y's parent then becomes x's parent.
  *		 If x's parent is equal to null, then x is at the root, so y gets the
  *		 rootPtr. Otherwise if x is on the left then it gets y's left child and
  *		 if it's on the right then it gets y's right child. Finally, x becomes
  *		 y's right child and y becomes x's parent.
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::rightRotate(BinaryNode* x)
{

	if (x->getLeftChildPtr() == nullptr)
	{
		return;
	}
	else
	{
		BinaryNode* y = x->getLeftChildPtr();
		x->setLeftChildPtr(y->getRightChildPtr());
		if (y->getRightChildPtr() != nullptr)
		{
			//x->setLeftChildPtr(y->getRightChildPtr());
			(y->getRightChildPtr())->setParent(x);
			//x->setParent(y);
		}
		/*else
		{
			x->setLeftChildPtr(nullptr);
		}*/
		y->setParent(x->getParent());
		/*if (x->getParent() != nullptr)
		{
			y->setParent(x->getParent());
		}*/
		if (x->getParent() == nullptr)
		{
			rootPtr = y;
		}
		else
		{
			if (x == (x->getParent())->getLeftChildPtr())
			{
				(x->getParent())->setLeftChildPtr(y);
			}
			else
			{
				(x->getParent())->setRightChildPtr(y);
			}
		}
		y->setRightChildPtr(x);
		x->setParent(y);
	}

}

/**
  * @brief Calls recursive destroyTree function
  *
  * @details Calls destroyTree function passing the rootPtr to it as a
  *			 starting node
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::clear()
{

	destroyTree(rootPtr);
	rootPtr = nullptr;

}

/**
  * @brief Calls recursive preorder function
  *
  * @details Calls preorder function passing the rootPtr to it as a starting
  *			 node
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::preorderTraverse(void visit(int&)) const
{

	preorder(visit, rootPtr);

}

/**
  * @brief Calls recursive inorder function
  *
  * @details Calls inorder function passing the rootPtr to it as a starting
  *			 node
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::inorderTraverse(void visit(int&)) const
{

	inorder(visit, rootPtr);

}

/**
  * @brief Calls recursive postorder function
  *
  * @details Calls postorder function passing the rootPtr to it as a starting
  *			 node
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void RedBlackTree::postorderTraverse(void visit(int&)) const
{

	postorder(visit, rootPtr);

}

