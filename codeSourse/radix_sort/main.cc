#include <iostream>
#include <cstring>
#include <array>

void counting_sort(int* arr, int* key_arr, int* unknown, int len) {
    int count[10] = {0};
    int rank[len + 1];
    memset(rank, 0, len + 1);
    for (int i = 0; i < len; i++) // 将关键字进行统计，每一位关键字都有多少个
        ++count[key_arr[i]];
    for (int i = 1; i < 10; i++) // 对统计的计数结果进行前缀和
        count[i] += count[i - 1];
    for (int i = len - 1; i >= 0; i--) // 逆序, 得到rank数组，也就是上一轮的排序结果原来的位置
        rank[unknown[i]] = count[key_arr[unknown[i]]]--;
    for (int i = 0; i < len; i++)
        unknown[rank[i]] = i;
}

void radix_sort(int* arr, int len, int key_len) {
    int sa[len + 1];
    int key_arr[len + 1];
    for (int i = 0; i < len; i++)
        sa[i] = i;
    int x = 1;
    for (int i = 0; i < key_len; i++, x *= 10) {
        for (int j = 0; j < len; j++)
            key_arr[j] = arr[j] / x % 10;
        counting_sort(arr, key_arr, sa, len);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    radix_sort(a, n, 3);
    return 0;
}