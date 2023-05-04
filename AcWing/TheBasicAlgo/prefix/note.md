## 前缀和  

> 假如有一个数组 $a_1, a_2, ..., a_n$ ，其前缀和 $s_i = a_1 + a_2 + ... + a_i$  
> **注意，前缀和的下标必须从1开始。为了方便处理边界**

- 如何求取前缀和
  - 直接递推从$i = 1 \rightarrow i = n$
- 作用
  - 能够快速求取元素中一段数的和

## 差分

> 差分其实就是前缀和的逆运算  
> 假如有一个数组 $a_1, a_2, ..., a_n$，构造数组 $b_1, b_2, ..., b_n$，使得 $a_i = b_1 + b_2 + ... + b_i$

- 作用
  - 简化前缀和区间[l, r] + C的时间复杂度