## 双指针

- 基本模板

```c++
for (i = 0, j = 0; i < n; i++) {
    while (j < i && check(i, j)) j++;
    // 下面是具体逻辑实现
}
```
- 核心思想
  - 将暴力 $O(n^2)$ 优化到 $O(n)$  

## 位运算

- lowbit  
  - x & -x = x & (~x + 1)  

## 离散化(整数)

> 值域很大，但是里面值的个数很小，但是又想要做下标，就需要离散化  

- 可能有重复元素，需要去重  
  - 使用 $erase(unique(alls.begin(), alls.end()), alls.end())$
- 如何算出每一个值的映射值
  - 二分

```c++
vector<int> alls;
// 排序 + 去重
sort(alls.begin(), alls.end());
alls.erase(unique(alls.begin(), alls.end()), alls.end());

// 二分，找到离散化对应的下标值
// 找到第一个 >= x 的位置
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;   // 如果 + 1，则说明从1, 2, ..., n开始映射
}
```  

## 区间合并

- 第一步，按照区间左端点排序
- 第二步，扫描，将可能含有的区间进行合并
  - 第一种，若全部包含，则不变
  - 第二种，只包含左端点，则右断点变化
  - 第三种，不包含，不变，区间数 + 1，更新为当前不包含的区间