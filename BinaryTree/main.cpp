#include "BinaryTree.h"

void test1()
{
	BTNode* a = new BTNode('A');
	BTNode* b = new BTNode('B');
	BTNode* c = new BTNode('C');
	BTNode* d = new BTNode('D');
	BTNode* e = new BTNode('E');
	a->_left = b;
	a->_right = c;
	b->_left = d;
	b->_right = e;
	PrevOrder(a);
	cout << endl;
	InOrder(a);
	cout << endl;
	PostOrder(a);
	cout << endl;
	LevelOrder(a);
}

int main()
{
	test1();
}