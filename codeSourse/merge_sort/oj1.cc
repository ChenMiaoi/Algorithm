/*
 * 给定n个整数，a1, a2, ..., an进行从小到大排序
 * */

#include <iostream>

int a[100001], b[100001];

void merge_sort(int* arr, int l, int r) {
    if (l == r)
        return;
    int m = (l + r) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    int p1 = l, p2 = m + 1, t = 0;
    while (p1 <= m && p2 <= r) {
        if (arr[p1] < arr[p2])
            b[t++] = arr[p1++];
        else
            b[t++] = arr[p2++];
    }
    while (p1 <= m)
        b[t++] = arr[p1++];
    while (p2 <= r)
        b[t++] = arr[p2++];
    for (int i = 0; i < t; i++)
        arr[i + l] = b[i];
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}