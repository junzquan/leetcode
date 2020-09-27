# [286. 墙与门](https://leetcode-cn.com/problems/walls-and-gates/)

## 广度优先搜索

```cpp
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;

        const int GATE = 0;
        const int EMPTY = INT_MAX;
        vector<int> dirs = {1, 0, -1, 0, 1};

        // 找出所有的门
        queue<pair<int, int>> q;
        int row = rooms.size();
        int col = rooms[0].size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (rooms[i][j] == GATE)
                    q.push(make_pair(i, j));

        // 以门为起点做bfs
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dirs[i];
                int dy = y + dirs[i + 1];
                if (dx < 0 || dy < 0 || dx >= row || dy >= col || rooms[dx][dy] != EMPTY) continue;
                rooms[dx][dy] = rooms[x][y] + 1;
                q.push(make_pair(dx, dy));
            }
        }
    }
};
```

- 以门为起点做广度优先搜索。

### 复杂度分析

- 时间复杂度：O(m * n)
- 空间复杂度：O(m * n)

