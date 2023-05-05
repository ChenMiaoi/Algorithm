#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

/**
 * 假定有无限长的数轴，数轴上的每个坐标的数都是0
 * 现在进行n次操作，每次操作将某个位置x上的数加c
 * 然后，进行m次询问，需要求出[l, r]之间所有数的和
 * */

// 前缀和如果在范围较小的情况下比较合适

const int N = 300010;

int n, m;
int a[N], s[N];
std::vector<int> alls;
std::vector<std::pair<int, int>> add, query;

int find(int x) {
    int l = 0, r = alls.size() - 1;

    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重
    std::sort(alls.begin(), alls.end());
    alls.erase(std::unique(alls.begin(), alls.end()), alls.end());

    // 处理插入
    for (auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }

    // 处理前缀和
    for (int i = 1; i <= alls.size(); i++) s[i] += s[i - 1] + a[i];

    // 处理询问
    for (auto item : query) {
        int l = find(item.first), r = find(item.second);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}