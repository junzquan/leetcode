# [542. 01 矩阵](https://leetcode-cn.com/problems/01-matrix/)

## 广度优先搜索

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const vector<int> dirs = {-1, 0, 1, 0, -1};
        const int row = matrix.size();
        const int col = matrix[0].size();
        vector<vector<int>> res(row, vector<int>(col, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                }
                else
                {
                    res[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> pos = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = pos.first + dirs[i];
                int dy = pos.second + dirs[i + 1];
                if (dx >= 0 && dx < row && dy >= 0 && dy < col && res[dx][dy] == -1)
                {
                    res[dx][dy] = res[pos.first][pos.second] + 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }

        return res;
    }
};
```

- 多源 `BFS` ，首先把每一个 `0` 的位置入队，把非 `0` 的位置重置为 `-1` ，代表没有被访问过；
- 然后从各个 `0` 开始一圈一圈地向外扩，并更新 `-1` 的点。

### 复杂度分析

- 时间复杂度：O(row * col)
- 空间复杂度：O(row * col)

