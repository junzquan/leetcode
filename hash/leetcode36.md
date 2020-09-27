# [36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        vector<vector<int>> box(9, vector<int>(10, 0));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.') continue;

                int curNum = board[i][j] - '0';
                if (row[i][curNum]) return false;
                if (col[j][curNum]) return false;
                if (box[i / 3 * 3 + j / 3][curNum]) return false;

                row[i][curNum] = 1;
                col[j][curNum] = 1;
                box[i / 3 * 3 + j / 3][curNum] = 1;	// 第 i/3*3 + j/3 个box的curNum出现过
            }
        }
        
        return true;
    }
};
```

#### 使用哈希表进行存储

> 存储每一行的每个数是否出现过，默认初始情况下，每一行的每一个数都没有出现过；
>
> 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过；
>
> 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过，整个board有9个box；
>
> 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)



