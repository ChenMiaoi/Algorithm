#include <iostream>
#include <vector>
#include <string>

template <typename _ty>
void quick_sort(_ty* arr, int left, int right) {
    if (left >= right)
        return;
    std::swap(arr[left], arr[left + std::rand() % (right - left + 1)]);
    _ty key = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && arr[j] > key)
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

template<typename _contain>
void quick_sort(_contain& contain, int left, int right) {
    if (left >= right)
        return;
    std::swap(contain[left], contain[left + std::rand() % (right - left + 1)]);
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