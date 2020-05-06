# [983. 最低票价](https://leetcode-cn.com/problems/minimum-cost-for-tickets/)

## 动态规划

```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> travel(days.back() + 1);
        vector<int> dp(days.back() + 1);
        dp[0] = 0;
        for (auto i : days) travel[i] = true;
        for (int i = 1; i < dp.size(); i++)
        {
            if (!travel[i])
            {
                dp[i] = dp[i - 1];
                continue;
            }
            dp[i] = dp[i - 1] + costs[0];
            dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
            dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
        }
        return dp.back();
    }
};
```

- `dp[i]` 表示第 `i` 天的最小花销，其中 `dp[0] = 0` ；
- 如果第 `i` 天没有旅行，则 `dp[i] = dp[i - 1]` ；
- 如果第 `i` 天有旅行，则 `dp[i] = min(dp[i - 1] + costs[0], dp[i - 7] + costs[1], dp[i - 30] +costs[2]` ，即买一天票、7天前买7天票和30天前买30天票之间的最小值。

### 复杂度分析

- 时间复杂度：O(1)
- 空间复杂度：O(1)
