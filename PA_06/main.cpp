#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "BinaryNode.h"
#include "BinarySearchTree.h"

using namespace std;

void visit(int&);

int main()
{

	srand (time(NULL));
	ofstream fout;
	fout.open("Output");
	bool* numExists1 = new bool[200];

	BinarySearchTree BST1;

	for (int i = 0; i < 200; i++)
	{
		numExists1[i] = false;
	}

	for (int i = 0; i < 100; i++)
	{
		int number = rand() % 200 + 1;
		while (numExists1[number])
		{
			number = rand() % 200 + 1;
		}
		numExists1[number] = true;
		BST1.add(number);	
	}

	fout << "================================================================================" << endl;
	fout << "BEGIN OUTPUT..." << endl;
	fout << "--------------------------------------------------------------------------------" << endl << "BST1 TREE UNALTERED" << endl << "--------------------------------------------------------------------------------" << endl;
	fout << "HEIGHT OF BST1: " << BST1.getHeight() << endl;
	fout << "INORDER TRAVERSAL OF BST1:" << endl;
	fout.close();

	BST1.inorderTraverse(visit);
	fout.open("Output", ios_base::app);
	fout << endl;

	bool* numExists2 = new bool[200];

	BinarySearchTree BST2;

	for (int i = 0; i < 200; i++)
	{
		numExists2[i] = false;
	}

	for (int i = 0; i < 10; i++)
	{
		int number = rand() % 200 + 1;
		while (numExists2[number] || !numExists1[number])
		{
			number = rand() % 200 + 1;
		}
		numExists2[number] = true;
		BST2.add(number);	
	}

	fout << "--------------------------------------------------------------------------------" << endl << "BST2 TREE UNALTERED" << endl << "--------------------------------------------------------------------------------" << endl;
	fout << "PREORDER TRAVERSAL OF BST2:" << endl;
	fout.close();

	BST2.preorderTraverse(visit);
	fout.open("Output", ios_base::app);
	fout << endl;
	fout << "INORDER TRAVERSAL OF BST2:" << endl;
	fout.close();

	BST2.inorderTraverse(visit);
	fout.open("Output", ios_base::app);
	fout << endl;
	fout << "POSTORDER TRAVERSAL OF BST2:" << endl;
	fout.close();

	BST2.postorderTraverse(visit);
	fout.open("Output", ios_base::app);
	fout << endl;

	for (int i = 0; i < 200; i++)
	{
		if (numExists2[i])
		{
			BST1.remove(i);
			numExists1[i] = false;
		}
	}

	fout << "--------------------------------------------------------------------------------" << endl << "BST1 TREE WITH VALUES IN BST2 REMOVED" << endl << "--------------------------------------------------------------------------------" << endl;
	fout << "HEIGHT OF NEW BST1: " << BST1.getHeight() << endl;
	fout << "NUMBER OF NODES IN NEW BST1: " << BST1.getNumberOfNodes() << endl;
	fout << "INORDER TRAVERSAL OF NEW BST1:" << endl;
	fout.close();

	BST1.inorderTraverse(visit);
	fout.open("Output", ios_base::app);
	fout << endl;

	fout << "--------------------------------------------------------------------------------" << endl << "EFFECTIVELY CLEARING THE TREES" << endl << "--------------------------------------------------------------------------------" << endl;

	fout << "BEFORE CLEARING BST1: " << endl;
	if (BST1.isEmpty())
	{
		fout << "BST1 is empty" << endl;
	}
	else
	{
		fout << "BST1 is not empty" << endl;
	}

	fout << "BEFORE CLEARING BST2: " << endl;
	if (BST2.isEmpty())
	{
		fout << "BST2 is empty" << endl;
	}
	else
	{
		fout << "BST2 is not empty" << endl;
	}

	BST1.clear();
	fout << "AFTER CLEARING BST1: " << endl;
	if (BST1.isEmpty())
	{
		fout << "BST1 is empty" << endl;
	}
	else
	{
		fout << "BST1 is not empty" << endl;
	}

	BST2.clear();
	fout << "BEFORE CLEARING BST2: " << endl;
	if (BST2.isEmpty())
	{
		fout << "BST2 is empty" << endl;
	}
	else
	{
		fout << "BST2 is not empty" << endl;
	}

	fout << "================================================================================" << endl;
	fout.close();

}

void visit(int& data)
{

	ofstream fout;
	fout.open("Output", ios_base::app);
	fout << data << ", ";
	fout.close();

}














