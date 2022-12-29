#include "Sort.h"

//√∞≈›≈≈–Ú
void BubbleSort(int* a, int len)
{
	int last_ex_sort = 0;
	int sort_board = len - 1;
	for (int i = 0; i < len - 1; i++)
	{
		bool is_over = true;
		for (int j = 0; j < sort_board; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = a[j];

				is_over = false;
				last_ex_sort = j;
			}
		}
		sort_board = last_ex_sort;
		if (is_over)
			break;
	}
}

//º¶Œ≤æ∆≈≈–Ú --   ”√”⁄Ω”Ω¸”––Ú
void SupperBubbleSort(int* a, int len)
{
	int temp = 0;
	for (int i = 0; i < len / 2; i++)
	{
		bool is_over = true;
		for (int j = i; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				is_over = false;
			}
		}
		if (is_over)
			break;

		is_over = true;
		for (int k = len - i - 1; k > i; k--)
		{
			if (a[k] < a[k - 1])
			{
				temp = a[k];
				a[k] = a[k - 1];
				a[k - 1] = temp;
				is_over = false;
			}
		}
		if (is_over)
			break;
	}
}

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int end = i; //[0, len - 2]
		int ref = a[end + 1];	//–Ë“™≈≈–Úµƒ÷µ
		while (end >= 0)
		{
			if (ref < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end + 1] = ref;
	}
	
}

//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n)
{

}

static int* partition(int* a, int* startIndex, int* endIndex)
{
	int pivot = *startIndex;
	int* left = startIndex;
	int* right = endIndex;

	while (left != right)
	{
		while (left < right && *right > pivot)
			right--;
		while (left < right && *left <= pivot)
			left++;
		if (left < right)
		{
			int temp = *left;
			*left = *right;
			*right = temp;
		}
	}

	*startIndex = *left;
	*left = pivot;
	return left;
}

//øÏÀŸ≈≈–Ú
void QuickSort(int* a, int* startIndex, int* endIndex)
{
	if (startIndex >= endIndex)
		return;

	int* pivoIndex = partition(a, startIndex, endIndex);
	QuickSort(a, startIndex, pivoIndex - 1);
	QuickSort(a, pivoIndex + 1, endIndex);
}
