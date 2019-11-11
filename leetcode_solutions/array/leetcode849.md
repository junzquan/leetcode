# [849. 到最近的人的最大距离](https://leetcode-cn.com/problems/maximize-distance-to-closest-person/)

```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int l = 0;
        int r = n - 1;
        while (l < n && seats[l] == 0)
        {
            l++;
        }       
        while (r >= 0 && seats[r] == 0)
        {
            r--;
        }
        int ret = max(l, n - 1 - r);
        
        for (int i = l + 1; i <= r; i++)
        {
            if (seats[i] == 1)
            {
                ret = max(ret, (i - l) / 2);
                l = i;
            }
        }
        return ret;
    }
};
```

- 首先统计左边和右边的 `0`；
- 然后统计中间的 `0`，将其除以 `2` 得到距离；
- 它们之间的最大值就是到最近的人的最大距离。



## 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)