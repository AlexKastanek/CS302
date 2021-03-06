// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file BinarySearchTree.cpp
  *
  * @brief Implementation file for BinarySearchTree class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the BinarySearchTree class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of BinarySearchTree class
  *
  * @note Requires BinarySearchTree.h
  *
  * @note None
  *
  */

#include "BinarySearchTree.h"

/**
  * @brief Constructor for class BinarySearchTree
  *
  * @details Able to construct a BinarySearchTree object
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
BinarySearchTree::BinarySearchTree()
{

	rootPtr = nullptr;

}

/**
  * @brief Constructor for class BinarySearchTree
  *
  * @details Able to construct a BinarySearchTree object with given parameters
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
BinarySearchTree::BinarySearchTree(int a)
{

	rootPtr = new BinaryNode(a);

}

/**
  * @brief Destructor for class BinarySearchTree
  *
  * @details Able to destruct a BinarySearchTree object
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
BinarySearchTree::~BinarySearchTree()
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
int BinarySearchTree::getHeightHelper(BinaryNode* subTreePtr) const
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
  * @brief Gets the number of nodes in the tree
  *
  * @details Recursively gets the number of nodes in the tree
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Returns 0 if there is no node, returns a 1 + a recursive call to the
  *		 left side of the subtree + a recursive call to the right side of the
  *		 subtree. This will eventually get you the total number of nodes
  *
  * @param subTreePtr - used as the root of the subTree, will call its left
  *		   side or right side depending on which one has more layers
  *
  * @exception None
  *
  * @note: None
  */
int BinarySearchTree::getNumberOfNodesHelper(BinaryNode* subTreePtr) const
{

	if (subTreePtr == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
	}

}

/**
  * @brief Places a node in the correct spot
  *
  * @details Recursively places a node in the correct numerical position
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 If there is no node there, it returns the newNode. In add, it will add
  *		 this newNode at the location where there is no node. If there is a
  *		 node, then it will recursively call either the left side of the sub
  *		 tree or the right side depending on the comparison of the values in
  *		 each side with the value in the new node
  *
  * @param subTreePtr - a pointer that points to the root of the subTree
  *		   newNodePtr - a pointer that points to the node that contains the
  *					    value that's being inserted
  *
  * @exception None
  *
  * @note: None
  */
BinaryNode* BinarySearchTree::placeNode(BinaryNode* subTreePtr, BinaryNode* newNodePtr)
{

	if (subTreePtr == nullptr)
	{
		return newNodePtr;
	}
	else if (subTreePtr->getItem() > newNodePtr->getItem())
	{
		BinaryNode* tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		BinaryNode* tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
		subTreePtr->setRightChildPtr(tempPtr);
	}

	return subTreePtr;

}

/**
  * @brief Searches for the value that will be removed
  *
  * @details Recursively searches for the value that will be removed
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Recursively calls itself until the value is found, and then calls
  *		 removeNode once it is found, sets isSuccessful to false if the node
  *		 does not exist
  *
  * @param subTreePtr - a pointer that points to the root of the subTree
  *		   target - an integer that is contained by the node that is targeted
  *				    for removal
  *		   isSuccessful - a bool that returns true if operation is successful
  *
  * @exception None
  *
  * @note: None
  */
BinaryNode* BinarySearchTree::removeValue(BinaryNode* subTreePtr, int target, bool& isSuccessful)
{

	if (subTreePtr == nullptr)
	{
		isSuccessful = false;
	}
	else if (subTreePtr->getItem() == target)
	{
		subTreePtr = removeNode(subTreePtr);
		isSuccessful = true;
	}
	else if (subTreePtr->getItem() > target)
	{
		BinaryNode* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		BinaryNode* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;

}

/**
  * @brief Removes a node from the tree
  *
  * @details Removes a node from the tree, calls removeLeftMostNode if the tree
  *			 has 2 children
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Gets the number of children of the node, if there are no children,
  *		 then the node gets deleted and set to null. If there is one child,
  *		 then a node to connect is built. If the one child is on the right then
  *		 the node to connect gets the right child and vice versa. The original
  *		 node then gets deleted but not set to null because it is being
  *		 replaced by the child node. If there are two children, then
  *		 removeLeftMostNode is called. The right child is then set to what this
  *		 function returns and the item is set to what this function changed it
  *		 to be
  *
  * @param nodePtr - points to the node that will be deleted
  *
  * @exception None
  *
  * @note: None
  */
BinaryNode* BinarySearchTree::removeNode(BinaryNode* nodePtr)
{

	int numOfChildren = nodePtr->getNumOfChildren();
	if (numOfChildren == 0)
	{
		delete nodePtr;
		nodePtr = nullptr;
		return nullptr;
	}
	else if (numOfChildren == 1)
	{
		BinaryNode* nodeToConnectPtr;
		if (nodePtr->getLeftChildPtr() != nullptr)
		{
			nodeToConnectPtr = nodePtr->getLeftChildPtr();
		}
		else
		{
			nodeToConnectPtr = nodePtr->getRightChildPtr();
		}
		delete nodePtr;
		return nodeToConnectPtr;
	}
	else
	{
		int newNodeValue;
		BinaryNode* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
		nodePtr->setRightChildPtr(tempPtr);
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}

}


/**
  * @brief Shifts the chain of nodes correctly to avoid disconnection
  *
  * @details Moves the left side of the node being removed up the chain so the
  *			 node can be removed correctly
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 If there is no left child node, then inorderSuccessor gets the current
  *		 item and removeNode is called, which should effectively handle one or
  *		 no children without calling removeLeftMostNode again. If there is a
  *		 left child node, then recrusively calls removeLeftMostNode. Once the
  *		 bottom of the chain is reached, tempPtr gets the node that was
  *		 removed. nodePtr sets tempPtr as itsleft child and then we begin to
  *		 make our way back up by returning nodePtr from the various recursive
  *		 function calls until the whole tree has shifted from that original
  *		 subTreePtr that was originally being removed
  *
  * @param nodePtr - the left subTreePtr of the original subTreePtr
  *		   inorderSuccessor - an integer passed by reference so the tree can be
  *		  					  shifted without losing any of its data
  *
  * @exception None
  *
  * @note: None
  */
BinaryNode* BinarySearchTree::removeLeftmostNode(BinaryNode* nodePtr, int& inorderSuccessor)
{

	if (nodePtr->getLeftChildPtr() == nullptr)
	{
		inorderSuccessor = nodePtr->getItem();
		return removeNode(nodePtr);
	}
	else
	{
		BinaryNode* tempPtr = removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
		nodePtr->setLeftChildPtr(tempPtr);
		return nodePtr;
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
void BinarySearchTree::destroyTree(BinaryNode* subTreePtr)
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
void BinarySearchTree::preorder(void visit(int&), BinaryNode* treePtr) const
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
void BinarySearchTree::inorder(void visit(int&), BinaryNode* treePtr) const
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
void BinarySearchTree::postorder(void visit(int&), BinaryNode* treePtr) const
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
bool BinarySearchTree::isEmpty() const
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
int BinarySearchTree::getHeight() const
{

	return getHeightHelper(rootPtr);

}

/**
  * @brief Calls recursive getNumberOfNodesHelper function
  *
  * @details Calls getNumberOfNodesHelper function passing the rootPtr to it as
  *			 a starting node
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
int BinarySearchTree::getNumberOfNodes() const
{

	return getNumberOfNodesHelper(rootPtr);

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
int BinarySearchTree::getRootData() const
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
BinaryNode* BinarySearchTree::getRootNode() const
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
void BinarySearchTree::setRootData(int data)
{

	rootPtr->setItem(data);

}

/**
  * @brief Calls recursive placeNode function
  *
  * @details Calls placeNode function passing the rootPtr to it as a starting
  *			 node
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 If rootPtr is null, then allocates memory for it and creates the
  *		 rootNode, else it allocates memory for a new node and calls placeNode
  *		 to place it
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
bool BinarySearchTree::add(int newData)
{

	if (rootPtr == nullptr)
	{
		rootPtr = new BinaryNode(newData);
	}
	else
	{
		BinaryNode* newNodePtr = new BinaryNode(newData);
		rootPtr = placeNode(rootPtr, newNodePtr);
	}

	return true;

}

/**
  * @brief Calls recursive removeValue function
  *
  * @details Calls removeValue function passing the rootPtr to it as a
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
bool BinarySearchTree::remove(int target)
{

	bool isSuccessful = false;
	rootPtr = removeValue(rootPtr, target, isSuccessful);
	return isSuccessful;

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
void BinarySearchTree::clear()
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
void BinarySearchTree::preorderTraverse(void visit(int&)) const
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
void BinarySearchTree::inorderTraverse(void visit(int&)) const
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
void BinarySearchTree::postorderTraverse(void visit(int&)) const
{

	postorder(visit, rootPtr);

}

