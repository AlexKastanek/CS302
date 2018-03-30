#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "BinaryNode.h"
#include "RedBlackTree.h"

using namespace std;

int sum = 0;

void display(int&);

void getSum(int&);

int main()
{

	srand (time(NULL));
	bool* numExists1 = new bool[10000];

	RedBlackTree RBT;

	for (int i = 0; i < 10000; i++)
	{
		numExists1[i] = false;
	}

	for (int i = 0; i < 1000; i++)
	{
		int number = rand() % 10000 + 1;
		while (numExists1[number])
		{
			number = rand() % 10000 + 1;
		}
		numExists1[number] = true;
		RBT.insert(number);
	}

	/*RBT.inorderTraverse(display);
	cout << endl;*/

	cout << "HEIGHT OF RED BLACK TREE: " << RBT.getHeight() << endl;

	RBT.inorderTraverse(getSum);
	cout << "SUM OF ALL NODES IN TREE: " << sum << endl;

	cout << "EMPTY STATUS BEFORE CLEAR OPERATION: " << RBT.isEmpty() << endl;

	RBT.clear();

	cout << "EMPTY STATUS AFTER CLEAR OPERATION: " << RBT.isEmpty() << endl;

}

void display(int& data)
{

	ofstream fout;
	fout.open("Output", ios_base::app);
	fout << data << ", ";
	cout << data << ", ";
	fout.close();

}

void getSum(int& data)
{
	sum = sum + data; //adding values to global variable sum
}














