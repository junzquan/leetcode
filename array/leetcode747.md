# [747. 至少是其他数字两倍的最大数](https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/)

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != maxIndex && nums[i] * 2 > nums[maxIndex])
                return -1;
        }
        return maxIndex;
    }
};

```

- 首席遍历数组，找到最大值的索引 `maxIndex` ；
- 再次遍历数组，当 `i != maxIndex` 且 `nums[i]` 的两倍大于最大值时，返回 `-1` ；
- 否则返回 `maxIndex`。



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)