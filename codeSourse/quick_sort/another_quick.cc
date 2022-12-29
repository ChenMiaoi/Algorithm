/*
 * 不再使用原地算法实现快排，而是通过额外的两个数组来存储
 * */

#include <iostream>

int a[100001], b[100001], c[100001];

void quick_sort(int l, int r) {
    if (l >= r)
        return;
    int key = a[l + (std::rand() << 15) % (r - l + 1)];
    int l1 = 0, l2 = 0, y = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] < key) // 将小于key的值，放入b空间中
            b[l1++] = a[i];
        else
            if (a[i] > key) // 将大于key的值，放入c空间中
                c[l2++] = a[i];
            else // 等于key的数量
                ++y;
    }
    for (int i = 0; i < l1; i++)
        a[l + i] = b[i];
    for (int i = 0; i < y; i++)
        a[l + l1 + i] = key;
    for (int i = 0; i < l2; i++)
        a[l + l1 + y + i] = c[i];
    quick_sort(l, l + l1 - 1);
    quick_sort(l + l1 + y, r);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    std::cout << "\n";
    return 0;
}