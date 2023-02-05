#include <iostream>

/**
 * 只出现一次的数字
 *      给你n个数字，其中有且仅有两个数字只出现了一次，其他所有数字都出现了两次，你需要
 *      找出这两个只出现了一次的数字, 且找到的两个数字请按从小到大顺序输出
 *
 * 解题思路：
 *      先对整体进行异或操作，看最后的结果的最高位是0还是1，然后根据最高为0、1分为两组
 *      分别异或，最高位为0一组异或的结果为较小的，为1的结果为较大的
 * */
auto work1() {
    int n = 0;
    int A[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int v = 0;
    for (int i = 0; i < n; i++)
        v ^= A[i]; // 对整体异或 -> 实际上就是较小和较大的异或 v = a ^ b
    int c = 0;
    for (; v; v >>= 1) // 判断整体异或结果有多少位
        c++;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] >> (c - 1) & 1) // 如果最高位为1，那么就进入b组
            b ^= A[i];
        else // 如果最高位为0，那么就进入a组
            a ^= A[i];
    }
    printf("min: %d, max: %d\n", a, b);
}

/**
 * 子集和
 *      给你一个整数n，定义f0 = 1，对于所有的i都属于[1, 2^n)， fi = sum(j&i=j且j<i)fj * i mod 1000000007
 *      请依次输出f0, f1, ..., f2^n-1
 * */
auto work2() {
    constexpr int p = 1000000007;
    int n = 0;
    int f[100001];
    scanf("%d", &n);
    f[0] = 1;
    for (int i = 1; i < 1 << n; i++) { // 1 << n ==> 2^n
        f[i] = 1;
        // j 是 i的子集，
        for (int j = (i - 1) & i; j; j = (j - 1) & i)
            f[i] += f[j], f[i] %= p;
        f[i] = 1LL * f[i] * i % p;
        printf("%d ", f[i]);
    }
}

int main() {
    work1();
    return 0;
}