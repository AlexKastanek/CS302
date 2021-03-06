#include "BinaryNode.h"

BinaryNode::BinaryNode()
{

	data = 0;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;

}

BinaryNode::BinaryNode(int dataSource)
{

	data = dataSource;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;

}

BinaryNode::BinaryNode(int dataSource, BinaryNode* leftSource, BinaryNode* rightSource)
{

	data = dataSource;
	this->leftChildPtr = leftSource;
	this->rightChildPtr = rightSource;

}

void BinaryNode::setItem(int source)
{

	data = source;

}

int BinaryNode::getItem() const
{

	return data;

}

bool BinaryNode::isLeaf() const
{

	return (rightChildPtr == nullptr && leftChildPtr == nullptr);

}

int BinaryNode::getNumOfChildren() const
{

	if (isLeaf())
	{
		return 0;
	}
	else if (getLeftChildPtr() != nullptr && getRightChildPtr() != nullptr)
	{
		return 2;
	}
	else
	{
		return 1;
	}

}

BinaryNode* BinaryNode::getParent() const
{

	return this->parent;

}

BinaryNode* BinaryNode::getLeftChildPtr() const
{

	return this->leftChildPtr;

}

BinaryNode* BinaryNode::getRightChildPtr() const
{

	return this->rightChildPtr;

}

/*Color BinaryNode::getLeftColor() const
{

	return leftColor;

}

Color BinaryNode::getRightColor() const
{

	return rightColor;

}*/

Color BinaryNode::getColor() const
{

	return color;

}

void BinaryNode::setParent(BinaryNode* source)
{

	this->parent = source;

}

void BinaryNode::setLeftChildPtr(BinaryNode* source)
{

	this->leftChildPtr = source;

}

void BinaryNode::setRightChildPtr(BinaryNode* source)
{

	this->rightChildPtr = source;

}

/*void BinaryNode::setLeftColor(Color source)
{

	leftColor = source;

}

void BinaryNode::setRightColor(Color source)
{

	rightColor = source;

}*/

void BinaryNode::setColor(Color source)
{

	color = source;

}





















