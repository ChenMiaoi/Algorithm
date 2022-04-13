#include "Sort.h"

//ð������
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

//��������
void InsertSort(int* a, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int end = i; //[0, len - 2]
		int ref = a[end + 1];	//��Ҫ�����ֵ
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

//ϣ������
void ShellSort(int* a, int n)
{

}