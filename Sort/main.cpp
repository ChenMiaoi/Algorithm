#include "Sort.h"

void test1()
{
	int a[10] = { 0, 2, 1, 4, 5, 9, 8, 6, 3, 7 };
	InsertSort(a, 10);
	for (auto e : a)
		cout << e << " ";
	cout << endl;
}

int main()
{
	test1();
}