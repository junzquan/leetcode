# [643. 子数组最大平均数 I](https://leetcode-cn.com/problems/maximum-average-subarray-i/)

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double res = sum;
        for (int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - nums[i - k];
            res = max(sum, res);
        }
        return res/k;
    }
};
```

- 使用固定长度为 `k` 的滑动窗口，首先算出前 `k` 个数的和；
- 每次窗口向右移动一位，相当于减去 `nums[i - k]` ，并加上 `nums[i]`。
-  然后每次更新结果 `res` 。



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)