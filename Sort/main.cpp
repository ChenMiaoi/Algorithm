#include "Sort.h"

void test1()
{
	int a[10] = { 0, 2, 1, 4, 5, 9, 8, 6, 3, 7 };
	SupperBubbleSort(a, 10);
	for (auto e : a)
		cout << e << " ";
	cout << endl;
}

void test2()
{
	int a[] = { 4,4,6,5,3,2,8,1 };
	int len = sizeof(a) / sizeof(a[0]);
	QuickSort(a, &a[0], &a[len - 1]);
	for (auto e : a)
		cout << e << " ";
	cout << endl;
}

int main()
{
	test2();
}