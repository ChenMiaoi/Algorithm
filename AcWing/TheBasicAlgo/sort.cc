#include <iostream>

using namespace std;

#if 0
const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return ;
    int mid = (l + r) / 2;
    int x = q[mid]; //当这个随机数取到l的时候，下面递归就必须是用right作为边界；
    //如果取到r，就必须用left作为边界，不然会出现死循环问题
    int left = l - 1, right = r + 1;
    while (left < right)
    {
        while (q[++left] < x);
        while (q[--right] > x);
        if (left < right)
            swap(q[left], q[right]);
    }
    quick_sort(q, l, right);
    quick_sort(q, right + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}
#endif // !0 快速排序

const int N = 1000010;
int n;
int q[N], temp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    
    int mid = r + l >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0;
    int left = l, right = mid + 1;
    while (left <= mid && right <= r)
    {    
        if (q[left] <= q[right])
            temp[k++] = q[left++];
        else
            temp[k++] = q[right++];
    }
    while (left <= mid)
        temp[k++] = q[left++];
    while (right <= r)
        temp[k++] = q[right++];

    for (left = l, right = 0; left <= r; right++, left++)
        q[left] = temp[right];
    
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    
    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    
    return 0;
}