/*
 * 稳定排序：
 *      给定n个整数，输出将他们从小到大排序后，每个数字应该排在第几位(对于相同的数字，
 *      序号小的排在前面)
 * */
#include <iostream>
#include <algorithm>

struct Node {
    int x, y;
    bool operator< (const Node& A) const {
        return x != A.x ? (x < A.x) : (y < A.y);
    }
};

void quick_sort(Node* a, int l, int r) {
    if (l >= r)
        return;
    std::swap(a[l], a[l + (std::rand() << 15) % (r - l + 1)]);
    auto key = a[l];
    int i = l, j = r;
    while (i < j) {
        while (i < j && key < a[j])
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
    Node a[10001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].x);
        a[i].y = i;
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        std:: cout << a[i].x << " ";
    }
    std::cout << "\n";
    int c[10001];
    for (int i = 0; i < n; i++)
        c[a[i].y] = i;
    for (int i = 0; i < n; i++)
        printf("%d ", c[i]);
    std::sort(a, a + n - 1, [](const Node& a1, const Node& a2) -> bool {
        return a1.x != a2.x ? (a1.x < a2.x) : (a1.y < a2.y);
    });
    return 0;
}