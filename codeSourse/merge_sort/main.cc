#include <iostream>

/*
 * 归并排序的复杂度是：nlogn
 * */

template <typename _ty>
void merge_sort(_ty* arr, int left, int right) {
    static _ty temp[100001];
    if (left == right) // 返回条件
        return;
    int mid = (left + right) / 2; // 找到归并的中间分段的值
    merge_sort(arr, left, mid); // 向左归并
    merge_sort(arr, mid + 1, right); // 向右归并
    // 以下是左右已经有序，合并操作
    int p1 = left, p2 = mid + 1, tot = 0;
    while (p1 <= mid && p2 <= right) { // 用一块额外的空间来合并，且保证顺序
        if (arr[p1] <= arr[p2])
            temp[tot++] = arr[p1++];
        else
            temp[tot++] = arr[p2++];
    }
    while (p1 <= mid) // 如果[p1, mid]里面还有元素，那么需要遍历
        temp[tot++] = arr[p1++];
    while (p2 <= right) // 如果[p2, right]里面还有元素，那么需要遍历
        temp[tot++] = arr[p2++];
    for (int i = 0; i < tot; i++) // 最后放回原数组
        arr[i + left] = temp[i];
}

template <typename _contain>
void merge_sort(_contain contain, int left, int right) {
    static _contain temp(contain.size());
    if (left == right)
        return;
    auto mid = (left + right) / 2;
    merge_sort(contain, left, mid);
    merge_sort(contain, mid + 1, right);
    int p1 = left, p2 = mid + 1, tot = 0;
    while (p1 <= mid && p2 <= right) {
        if (contain[p1] <= contain[p2])
            temp[tot++] = contain[p1++];
        else
            temp[tot++] = contain[p2++];
    }
    while (p1 <= mid)
        temp[tot++] = contain[p1++];
    while (p2 <= right)
        temp[tot++] = contain[p2++];
    for (int i = 0; i < tot; i++)
        contain[i + left] = temp[i];
}

int main() {
    int a[5] = {2, 3, 1, 0, 5};
    merge_sort(a, 0, 5 - 1);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    return 0;
}