# [695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)

## 广度优先搜索

```cpp
class Solution {
public:
    enum GridType {
        WATER = 0,
        LAND,
    };

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> land(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == LAND && land[i][j] == false)
                {
                    bfs(grid, land, i, j, res);
                }
            }
        }
        return res;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& land, int i, int j, int& res)
    {
        vector<int> dirs = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        land[i][j] = true;
        int area = 0;
        while (!q.empty())
        {
            pair<int, int> cur_land = q.front();
            q.pop();
            area++;
            for (int i = 0; i < 4; i++)
            {
                int dx = cur_land.first + dirs[i];
                int dy = cur_land.second + dirs[i + 1];
                if (dx < 0 || dy < 0 || dx >= grid.size() || dy >= grid[0].size())
                    continue;
                if (grid[dx][dy] == LAND && land[dx][dy] == false)
                {
                    land[dx][dy] = true;
                    q.push(make_pair(dx, dy));
                }
            }
        }
        res = max(res, area);
    }
};
```

- 对每一片没有被访问过的土地进行广度优先搜索；
- 使用一个二维数组 `land` 来记录土地是否已被访问，对于一片土地的四个方向，如果未被访问且是土地的话，将其加入队列 `queue` 。

### 复杂度分析

- 时间复杂度：O(R * C)，R 是网格的行数，C 是网格的列数；
- 空间复杂度：O(R * C)

