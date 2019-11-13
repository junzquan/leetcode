# [840. 矩阵中的幻方](https://leetcode-cn.com/problems/magic-squares-in-grid/)

```cpp
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ret = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row - 2; i++)
        {
            for (int j = 0; j < col - 2; j++)
            {
                if (valid(grid, i, j))
                    ret++;
            }
        }
        return ret;
    }

private:
    bool valid(vector<vector<int>>& grid, int r, int c)
    {
        if (grid[r + 1][c + 1] != 5) return false;
        unordered_set<int> num_set;
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int cur = grid[r + i][c + j];
                if (cur < 1 || cur > 9 || num_set.find(cur) != num_set.end())
                    return false;
                else
                    num_set.insert(cur);
            }
        }
        
        for (int i = 0; i < 3; i++)
        {
            int n1 = 0;
            int n2 = 0;
            for (int j = 0; j < 3; j++)
            {
                n1 += grid[r + i][c + j];
                n2 += grid[r + j][c + i];
            }
            if (n1 != 15 || n2 != 15)
                return false;
        }
        return true;
    }
};
```

- 根据题意，每个幻方的中心一定是5；
- 且每行每列都等于15。



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)