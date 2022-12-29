/*
 * 多关键字排序：
 *      先以第一关键字为基准排序，如果遇到第一关键字相同，那就以第二关键字为基准，以此类推
 *      比如：
 *          先以横坐标排序，如果横坐标相同，那就依据纵坐标来排序
 * */
#include <iostream>
#include <algorithm>

// 可以通过仿函数来实现
struct Node {
    int x, y;
    bool operator< (const Node& A) const {
        return x != A.x ? (x < A.x) : (y < A.y);
    }
};

void quick_sort(Node* arr, int left, int right) {
    if (left >= right)
        return;
    std::swap(arr[left], arr[left + (std::rand() << 15) % (right - left + 1)]);
    auto key = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && key < arr[j]) // 注意，这里因为只重载了 < ，所以需要改变顺序
            j--;
        if (i < j)
            arr[i++] = arr[j];
        while (i < j && arr[i] < key)
            i++;
        if (i < j)
            arr[j--] = arr[i];
    }
    arr[i] = key;
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

int main() {
    Node a[5] = {
            {1, 2},
            {1, 1},
            {2, 1},
            {0, 5},
            {2, 0}
    };
    quick_sort(a, 0, 5);
    for (auto i : a)
        std::cout << i.x << " : " << i.y << "\n";
    std::cout << "\n";
    // 对应的sort
    std::sort(a, a + 4, [](const Node& a1, const Node& a2) -> bool {
        return a1.x != a2.x ? (a1.x < a2.x) : (a1.y < a2.y);
    });
    for (auto i : a)
        std::cout << i.x << " : " << i.y << "\n";
    return 0;
}