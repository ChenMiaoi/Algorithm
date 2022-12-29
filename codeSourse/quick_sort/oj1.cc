/*
 * 给定n个整数，a1, a2, ..., an进行从小到大排序
 * */

#include <iostream>

int a1[100001];

void quick_sort(int* a, int l, int r) {
    if (l >= r)
        return;
    std::swap(a[l], a[l + (std::rand() << 15) % (r - l + 1)]);
    int key = a[l];
    int i = l, j = r;
    while (i < j) {
        while (i < j && a[j] > key)
            j--;
        if (i < j)
            a[i++] = a[j];
        while (i < j && a[i] < key)
            i++;
        if (i < j)
            a[j--] = a[i];
    }
    a[i] = key;
    quick_sort(a, l, i - 1);
    quick_sort(a, i + 1, r);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }
    quick_sort(a1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", a1[i]);
    }
    return 0;
}