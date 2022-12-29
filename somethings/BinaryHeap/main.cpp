#include "BinaryHeap.h"

void test1()
{
	int a[] = { 1,3,2,6,5,7,8,9,10,0 };
	int len = sizeof(a) / sizeof(a[0]);
	upAdjust(a, len);
	for (const auto e : a)
		cout << e << " ";
	cout << endl;

	int b[] = { 7,1,3,10,5,2,8,9,6 };
	len = sizeof(b) / sizeof(b[0]);
	creatHeap(b, len);
	for (const auto e : b)
		cout << e << " ";
	cout << endl;
}

int main()
{
	test1();
}