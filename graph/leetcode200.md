# [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)

## 广度优先搜索

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '0') continue;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                res++;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int dx = x + dirs[k];
                        int dy = y + dirs[k + 1];
                        if (dx < 0 || dy < 0 || dx >= m || dy >= n || grid[dx][dy] == '0')
                            continue;
                        grid[dx][dy] = '0';
                        q.push(make_pair(dx, dy));
                    }
                }
            }
        }

        return res;
    }
};
```

### 复杂度分析

- 时间复杂度：O(m * n)
- 空间复杂度：O(m * n)

