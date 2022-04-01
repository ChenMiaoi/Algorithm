#include "Sort.h"

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