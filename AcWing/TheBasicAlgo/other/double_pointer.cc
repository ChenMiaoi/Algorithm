#include <iostream>
#include <cstring>

/**
 * 应用一，将单词分割，以空格作为分隔符
 * */

void word() {
    char str[1000];
    gets(str);

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && str[j] != ' ') j++;
        // 以下具体逻辑
        for (int k = i; k < j; k++) printf("%c", str[k]);
        printf("\n");

        i = j;
    }
}

/**
 * 应用二，给定一个长度为n的整数序列，找出最长的不包含重复数字的连续子序列
 * */

const int N = 100010;

int n;
int a[N], s[N];

int max_sequence() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        s[a[i]]++;
        while (s[a[i]] > 1) {
            s[a[j]]--;
            j++;
        }

        res = std::max(res, i - j + 1);
    }
    return res;
}

int main() {
    // word();
    std::cout << max_sequence();
    return 0;
}