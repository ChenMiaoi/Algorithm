#include "BinaryHeap.h"

void upAdjust(int* a, int len)
{
	int childIndex = len - 1;
	int parentIndex = (childIndex - 1) / 2;

	int temp = a[childIndex];
	while (childIndex > 0 && temp < a[parentIndex])
	{
		a[childIndex] = a[parentIndex];
		childIndex = parentIndex;
		parentIndex = (parentIndex - 1) / 2;
	}
	a[childIndex] = temp;
}

void downAdjust(int* a, int parentIndex, int len)
{
	int temp = a[parentIndex];
	int childIndex = 2 * parentIndex + 1;
	while (childIndex < len)
	{
		if (childIndex + 1 < len && a[childIndex + 1] < a[childIndex])
			childIndex++;
		if (temp <= a[childIndex])
			break;
		a[parentIndex] = a[childIndex];
		parentIndex = childIndex;
		childIndex = childIndex * 2 + 1;
	}
	a[parentIndex] = temp;
}

void creatHeap(int* a, int len)
{
	for (int i = (len - 2) / 2; i >= 0; i--)
		downAdjust(a, i, len);
}