# [941. 有效的山脉数组](https://leetcode-cn.com/problems/valid-mountain-array/)

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        int i = 0;
        
        while (i + 1 < N && A[i] < A[i + 1])
            i++;
        
        if (i == 0 || i == N - 1)
            return false;
        
        while (i + 1 < N && A[i] > A[i + 1])
            i++;
        
        return i == N - 1;
    }
};
```

- 首先往山峰上走，遇到峰顶停下；
- 判断此时 `i` 的位置，如果 `i == 0` 或者 `i == N - 1`  ，则数组没有山峰，返回 `false` ；

- 然后往下走，最后返回 `i == N - 1 `，如果不相等，则证明山峰后的元素不是单调递减的。



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)