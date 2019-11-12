# [300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

## 动态规划

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
        }
        
        int ret = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
```

- **`dp[i]` 表示以 `nums[i]` 这个数结尾的最长递增子序列的长度**
- 根据状态转移方程构建 `dp` 数组：

$$
dp(i) = max\{\ dp(i),\ dp(j)\ +\ 1\ |\ j\in [0, i]\},\ nums[i] > nums[j]
$$

### 复杂度分析

- 时间复杂度：O(N<sup>2</sup>)
- 空间复杂度：O(N)



## 二分查找

