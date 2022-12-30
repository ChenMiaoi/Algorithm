#include <iostream>
#include <vector>
#include <algorithm>

/*
 * 计数排序：
 *      计数排序适合值域范围比较小的数字排序
 *
 * 如何保证稳定性：
 *      对于相同的数字，越后出现的排在越后面
 *      只需要逆序确认原本每个位置的数字最后排在第几位即可
 * */

template <typename _ty>
void count_sort(_ty& contain) {
    // 找到需要遍历中的最大值
    const int max = *std::max_element(contain.begin(), contain.end());
    _ty temp(max + 1); // 创建一个中间数组用于hash
    _ty r(contain.size()); // 创建一个中间数组用于稳定排序
    for (int i = 0; i < contain.size(); i++)
        temp[contain[i]]++; // 用于统计每一位数据的个数
    for (int i = 0; i <= max; i++) // 通过该循环，得出有序数组
        for (int j = 0; j < temp[i]; j++)
            printf("%d ", i);
    printf("\n");

    // 下面用于稳定排序
    for (int i = 1; i <= max; i++) // 遍历得到前缀和也就是Ci <= Ai，也就是小于等于其数据的个数之和
        temp[i] += temp[i - 1];
    for (int i = contain.size() - 1; i; i--) // 用于判断数据排序后应该在第几位
        r[i] = temp[contain[i - 1]]--; // 必须逆序遍历
    for (int i = 0; i < contain.size(); i++)
        printf("%d ", r[i]);
    printf("\n");
}

int main() {
    std::vector<int> a {3, 9, 5, 3, 2};
    count_sort(a);
    return 0;
}