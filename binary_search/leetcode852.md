# [852. 山脉数组的峰顶索引](https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/)

## 二分查找

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0;
        int hi = A.size() - 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] < A[mid + 1])
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};
```

- 如果 `A[mid] < A[mid + 1]`，则到后半区间去找；
- 否则在前半区间找。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)

