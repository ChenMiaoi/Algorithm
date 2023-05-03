#include <iostream>

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r - 1] -= c;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) insert(i, i, a[i]);    // 使b[i] = a[i]

    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);                                        // 使b[i] = a[i] + c
    }
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];              // 得到a[i] + c的前缀和
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    return 0;
}