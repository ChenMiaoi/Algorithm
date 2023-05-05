#include <iostream>

int lowbit(int x) {
    return x & -x;
}

/**
 * 计算每位数的二进制中有多少位是1
 * */

int bit_eq_1_num(int x) {
    int res = 0;
    while (x) x -= lowbit(x), res++;    // 每次减去最后一位1
    return res;
}

int main() {
    std::cout << bit_eq_1_num(5) << "\n";
    return 0;
}