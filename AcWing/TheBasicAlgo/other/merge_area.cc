#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

const int N = 100010;

int n;
std::vector<std::pair<int, int>> segs;

void merge(std::vector<std::pair<int, int>>& s) {
    std::vector<std::pair<int, int>> res;

    // 排序，首先按照第一关键字排序，然后按照第二关键字排序
    std::sort(s.begin(), s.end());

    // 初始化区间
    int st = -2e9, ed = -2e9;
    for (auto seg : s) {
        if (ed < seg.first) {   // 如果区间的左端点大于当前的区间ed
            if (st != -2e9) res.push_back({st, ed});     // 存入新区间
            st = seg.first, ed = seg.second;                    // 更新区间
        } else {                // 当前区间包含其左端点，则看谁的ed更长
            ed = std::max(ed, seg.second);
        }
    }

    // 加入最后一个区间
    if (st != -2e9) res.push_back({st, ed});
    segs = res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }

    merge(segs);

    printf("%zd\n", segs.size());
    return 0;
}