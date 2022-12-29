#include <iostream>
#include <vector>
#include <string>

/*
 * 快排最好的时间复杂度是：nlogn
 *    最坏的时间复杂度是：n^2
 * #include <algorithm>
 * std::sort()
 * */

template <typename _ty>
void quick_sort(_ty* arr, int left, int right) {
    if (left >= right) // 当left >= right的时候，说明已经排序完成了，开始返回
        return;
    // 防止最坏的O(n^2)的情况出现，所以选取的界限值需要随机处理
    // 在Windows下，rand一般是2^15 - 1，也就是7FFF，显然这没办法使其在[l, r]区间
#if linux
    std::swap(arr[left], arr[left + std::rand() % (right - left + 1)]);
#elif WIN64 && WIN32
    std::swap(arr[left], arr[left + (std::rand() << 15) % (right - left + 1)]);
#endif
    _ty key = arr[left]; // 设置一个值，作为界限进行分块，左边小于右边大于
    int i = left, j = right; // 通过指针来交换两个位置，i和j分别是索引值
    while (i < j) { // 迭代范围是：i < j
        while (i < j && arr[j] > key) // 跳过中间大于key的
            // 条件为：j向左找，找到第一个小于key的
            j--;
        if (i < j) // 将找到第一个小于key的值arr[j]放入arr[i]中
            arr[i++] = arr[j];
        while (i < j && arr[i] < key) // 跳过中间小于key的
            // 条件为：i向右找，找到第一个大于key的
            i++;
        if (i < j) // 将找到第一个大于keu的值arr[i]放入arr[j]中
            arr[j--] = arr[i];
    }
    arr[i] = key; // 左右两边处理完后，处理中间
    quick_sort(arr, left, i - 1); // [left, key - 1]
    quick_sort(arr, i + 1, right); // [key + 1, right]
    // 注意，此处的区间不能弄错
}

template<typename _contain>
void quick_sort(_contain& contain, int left, int right) {
    if (left >= right)
        return;
#if linux
    std::swap(contain[left], contain[left + std::rand() % (right - left + 1)]);
#elif WIN64 && WIN32
    std::swap(contain[left], contain[left + (std::rand() << 15) % (right - left + 1)]);
#endif
    auto key = contain[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && contain[j] > key)
            j--;
        if (i < j)
            contain[i++] = contain[j];
        while (i < j && contain[i] < key)
            i++;
        if (i < j)
            contain[j--] = contain[i];
    }
    contain[i] = key;
    quick_sort(contain, left, i - 1);
    quick_sort(contain, i + 1, right);
}

int main() {
    int arr[] = {2, 3, 1, 5, 6, 9, 7, 8, 4, 0};
    quick_sort(arr, 0, 9);
    for (auto i : arr)
        std::cout << i << " ";
    std::cout << "\n";
    std::vector<int> v = {2, 3, 1, 5, 6, 9, 7, 8, 4, 0};
    quick_sort(v, 0, v.size() - 1);
    for (auto i : v)
        std::cout << i << " ";
    return 0;
}