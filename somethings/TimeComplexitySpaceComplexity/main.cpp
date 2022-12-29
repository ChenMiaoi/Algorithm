#include <iostream>
#include <Windows.h>

using namespace std;
#if 0
/*
	渐近时间复杂度：
		若存在函数f(n)，使得当n趋近于无穷大时，T(n)/f(n)的极限值是不为零的常数，则称f(n)是T(n)的同数量级函数
		记作：T(n) = O(f(n)).
		O为算法的渐近时间复杂度，简称时间复杂度 -- 大O表示法

	原则：
		1.如果运行时间是常数量级，则用常数1表示
		2.只保留时间函数中的最高阶项
		3.如果最高阶项存在，则省去最高阶项前面的系数
*/

//10cm面包，每三分钟吃1cm
void eat1()
{
	int n = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		Sleep(3000);
		cout << "恰一口面包" << endl;
	}
	//由上述可以算出，T(n) = 3n，执行次数是线性的
	//T(n) = O(n)
}

//16cm面包，每五分钟吃掉一半，吃到只剩1cm
void eat2()
{
	int n = INT_MAX;
	for (int i = n; i > 1; i /= 2)
	{
		Sleep(5000);
		cout << "恰一半面包" << endl;
	}
	//由上述可以算出，T(n) = 5logn,执行次数是对数计算的
	//T(n) = O(logn)
}

//每两分钟吃掉一个鸡腿，吃掉整个鸡腿
void eat3()
{
	int n = INT_MAX;
	Sleep(2000);
	cout << "吃完一个鸡腿" << endl;
	//由上述可以算出，T(n) = 2，执行次数是常量
	//T(n) = O(1)
}

//10cm面包，每吃1cm的时间递增一分钟，第1cm为1分钟
void eat4()
{
	int n = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			Sleep(1000);
		}
		cout << "恰一口面包" << endl;
	}
	//由上述可以算出，T(n) = 0.5n^2 + 0.5n,执行次数使用多项式计算的
	//T(n) = O(n^2)
}

/*
** 因此，有这个结论：O(1) < O(logn) < O(n) < O(n^2)
** 除此之外，还有：O(nlogn)、O(n^3)、O(mn)、O(2^n)、O(n!)
*/

int main()
{
	eat1();
	eat2();
	eat3();
	eat4();
}
#endif // !0 时间复杂度

#if 0
/*
	空间复杂度：
		对一个算法在运行过程中临时占用存储空间大小的度量--同样使用大O表示法
	S(n) = O(f(n))
		n为问题的规模，f(n)为算法占存的函数
*/

/*
** 常量空间
** 当算法的存储空间大小固定，和输入规模没有直接关系的时候，空间复杂度记作O(1)
*/
void func1()
{
	int var = 3;
	//TODO...
}

/*
** 线性空间
** 当算法分配的空间是一个线性的集合(如数组),并且集合大小和输入规模n成正比时，空间复杂度记作O(n)
*/
void func2()
{
	int n = INT_MAX;
	int* arr = new int[n];
}

/*
** 二维空间
** 当算法分配的空间是一个二维数组的集合，并且集合的长度和宽度都与输入规模n成比例，空间复杂度为O(n^2)
*/
void func3()
{
	int n = CHAR_MAX;
	int matrix[CHAR_MAX][CHAR_MAX];
}

/*
** 递归空间
** 递归不会显式的声明变量或集合，但是在执行的时候，会开辟一块空间，存储"方法调用栈"
** "方法调用栈"包括： 1.出栈    2.入栈
** 纯粹的递归操作的空间复杂度也是线性的，如果递归的深度是n，那么空间复杂度记作O(n)
*/
void func4()
{
	static int n = INT_MAX;
	if (n <= 1)
		return;
	n--;
	func4();
}

int main()
{
	func1();
	func2();
	func3();
	func4();
}
#endif // !0 空间复杂度

/*
	时间与空间的取舍：
		1.牺牲时间换取空间
		2.牺牲空间换取时间
	但对于现代计算机，时间复杂度更为重要一点，因此，在绝对多数情况下都是以空间换时间
*/