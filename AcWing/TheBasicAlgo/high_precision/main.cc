#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool cmp(std::vector<int>& A, std::vector<int>& B) {
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}

struct div_ref {
    std::vector<int> C;
    int r;
};

std::vector<int> add(std::vector<int>& A, std::vector<int>& B) {
    std::vector<int> C; // 返回结果
    int t = 0; // 用于记录进位
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i]; // 相当于 t = A + B + t
        C.push_back(t % 10); // 存入A + B相加后的个位
        t /= 10; // 如果发生进位，那么就会 / 10
    }
    if (t) // 如果到了最高位 t 不为零的话，就说明最高位也需要进位
        C.push_back(t);
    return C;
}

// 首先得保证 A >= B
std::vector<int> sub(std::vector<int>& A, std::vector<int>& B) {
    std::vector<int> C; // 返回结果
    for (int i = 0, t = 0; i < A.size(); i++) { // t用于记录借位
        /**
         * 在最开始的时候，t = 0
         * t = A - B，if t < 0 就说明A < B，需要向高位借1
         * 而，从第一步往后就是
         * t = A - B - t，此处的t就是是否借位，借位了就减一
         * */
        t = A[i] - t;
        if (i < B.size()) // 因为我们限制了A >= B，因此，这里得判断i不能超过B的位数
            t = t - B[i];
        /**
         * 这里的 (t + 10) % 10，其实是两步的
         * if t > 0，也就是说，A > B，push t % 10
         * if t < 0，也就是说，A < B，此时的t是负数，我们需要加上10表示借位了，再push t % 10
         * 但是，我们发现 (t + 10) % 10，其实可以同时表示两种状态，因此就合并了
         * */
        C.push_back((t + 10) % 10);
        if (t < 0) // 判断是否借位
            t = 1;
        else
            t = 0;
    }
    // 这里是防止借位后出现前导0
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

// 默认是一个大数和一个小整数的乘法
std::vector<int> mul(std::vector<int>& A, size_t b) {
    std::vector<int> C; // 返回结果
    int t = 0; // 判断是否进位
    for (int i = 0; i < A.size() || t; i++) { // 也要判断进位是否处理完毕
        if (i < A.size()) // 防止数据已经处理完了，但是进位还未处理完的情况
            t = t + A[i] * b; // 每一位之和 = 每一位和小数的乘积 + 上一位的进位
        C.push_back(t % 10); // 取余就得到个位
        t = t / 10; // 进位
    }
    return C;
}

// 默认是一个大数和一个小整数的除法
// 返回一个商和余数
div_ref div(std::vector<int>& A, size_t b) {
    std::vector<int> C; // 返回结果
    int r = 0; // 返回余数
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i]; // An-1 = An + r * 10，下一位的被除数是上一位的余数加上下一位本身
        C.push_back(r / b); // 除以b得到对应的商，注意此处是高位在前的
        r %= b; // 每一位的余数
    }
    // 在计算存储的时候，是最高位在前面的，因为除法是从头开始除，如果要和前面三种运算输出一致，就得逆置
    std::reverse(C.begin(), C.end());
    // 去除前导零
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return {C, r};
}

int main() {
    std::vector<int> A, B;
    std::string a, b;
    std::cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    std::vector<int> C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    return 0;
}