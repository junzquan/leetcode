# [999. 车的可用捕获量](https://leetcode-cn.com/problems/available-captures-for-rook/)

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'R')
                {
                    int up = i;
                    while (up > 0)
                    {
                        if (board[up][j] == 'p')
                        {
                            ans++;
                            break;
                        }
                        if (board[up][j] == 'B') break;
                        up--;
                    }
                    
                    int down = i;
                    while (down < board.size())
                    {
                        if (board[down][j] == 'p')
                        {
                            ans++;
                            break;
                        }
                        if (board[down][j] == 'B') break;
                        down++;
                    }
                    
                    int left = j;
                    while (left > 0)
                    {
                        if (board[i][left] == 'p')
                        {
                           ans++;
                           break; 
                        }
                        if (board[i][left] == 'B') break;
                        left--;
                    }
                    
                    int right = j;
                    while (right < board[0].size())
                    {
                        if (board[i][right] == 'p')
                        {
                            ans++;
                            break;
                        }
                        if (board[i][right] == 'B') break;
                        right++;
                    }
                }
            }
        }
        
        return ans;
    }
};
```

