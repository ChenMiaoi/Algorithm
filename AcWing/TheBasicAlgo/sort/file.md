- 快速排序
  - 基于分治
    - 1. 确定分界点：左边界、右边界、中间值
    - 2. **(难点)** 调整范围：使得在区间内的所有数左边的数小于等于x，右边的数大于等于x
    - 3. 递归处理左右两端

  - 对于第二步的解决方法(暴力)：
    - 1. 定义两个空间a[], b[]
    - 2. 将q[l ~ r]区间中的分别进行以下操作：
      - 1. q[i] <= x, q[i] --> a[]
      - 2. q[i] >= x, q[i] --> b[]
    - 3. 将a[]放入q[]中，将b[]放入q[]中

  - 优化第二步的解决方法：
    - 1. 定义两个指针i, j分别指向l, r
    - 2. 在q[l ~ r]中进行如下操作：
      - 1. 如果i <= x, 则说明i的位置不用变化，直到i >= x, 遍历结束，交换i,j
      - 2. 当i的遍历结束后, 进行j的操作，如果j >= x, 则说明j的位置不用变化，直到j <= x，遍历结束，交换i,j
      - 3. 不断进行上述操作，直到i和j相遇为止

> **快排是不稳定的，但是可以通过KV来固定解决不稳定的问题(用a[i] = <a[i], i>)**

--- 

- 归并排序
  - 基于分治
    - 1. 确定分界点mid
    - 2. 递归排序[left ~ mid]，[mid ~ right]
    - 3. **(难点)** 归并 -- 合二为一

  - 归并的解决方法
    - 1. 双指针问题
    - 2. 对于第二步，用两个定义的空间存放a[], b[]
    - 3. 定义一个空间ref[]，分别比较上述两个空间的元素：
      - 1. 如果a[i] < b[i]，将a[i]存入ref[]，同时a[]向后移动一位继续比较，直到a[i] > b[i]为止
      - 2. b[]向后移动一位，重复上述步骤

> **归并是稳定的**

---  

- 二分法
  - (整数)二分
    - 二分的本质并不是单调性，有单调性的一定能二分，但反之不一定。**本质是边界** 
    - 第一种情况，mid = (l + r + 1) / 2
      - 1. 找到中间值mid，判断mid是否满足边界条件
      - 2. 如果check(mid)：
        - true --> [mid, r]
        - false --> [l, mid - 1]
      - 3. 更新区间，重复上述过程
    - 第二种情况，mid = (l + r) / 2
      - 1. 找到中间值mid，判断mid是否满足边界条件
      - 2. 如果check(mid)：
        - true --> [l, mid]
        - false --> [mid + 1, r]
      - 3. 更新区间，重复上述过程
    - 如何选择上述两种情况，看mid的取值以及更新区间
      - 对于第一种，如果l = r - 1,mid = (l + r) / 2 = l，那么如果这样check(mid)为true时，mid = l，则会陷入死循环，因此要+1