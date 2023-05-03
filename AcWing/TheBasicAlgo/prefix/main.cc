#include <iostream>

/**
 * 输入一个长度为n的整数序列，接下来输入m个询问，每个询问输入一对l，r
 * 对于每个询问，输出原序列中从第l个数到第r个数的和
 * */

const int N = 100010;

int n, m;
int a[N], s[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}