# [724. 寻找数组的中心索引](https://leetcode-cn.com/problems/find-pivot-index/)

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int leftSum = 0;
        for (auto i : nums)
            sum += i;
        for (int i = 0; i < nums.size(); i++)
        {
            if (leftSum == sum - leftSum - nums[i])
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
```

- 首先统计出 `nums` 所有元素的和 `sum`；
- 然后遍历 `nums`，更新 `i` 左边的和 `leftSum`，如果找到 `leftSum == sum - leftSum - nums[i]`，证明找到了中心索引；
- 否则返回 `-1`。



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)