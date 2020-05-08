# [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)

## 动态规划

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
                    res = max(dp[i][j], res);
                }
            }
        }

        return res * res;
    }
};
```

- `dp[i][j]` 表示以坐标点 `(i,j)` 为右下角的最大正方形。

### 复杂度分析

- 时间复杂度：O(N * M)
- 空间复杂度：O(N * M)
