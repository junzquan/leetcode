# [661. 图片平滑器](https://leetcode-cn.com/problems/image-smoother/)

```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        const vector<vector<int>> dir = {{1, 0}, {-1, 0}, 
                                         {0, -1}, {0, 1},
                                         {-1, -1}, {1, 1},
                                         {-1, 1}, {1, -1}
                                        };
        vector<vector<int>> ans = M;
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M[0].size(); j++)
            {
                ans[i][j] = getGrayScale(i, j, M, dir);
            }
        }
        return ans;
    }
    
private:
    int getGrayScale(int i, int j, vector<vector<int>>& M, const vector<vector<int>>& dir)
    {
        int sum = M[i][j];
        int cnt = 1;
        for (auto& v : dir)
        {
            int row = i + v[0];
            int col = j + v[1];
            if (row < 0 || col < 0 || row >= M.size() || col >= M[0].size())
                continue;
            sum += M[row][col];
            cnt++;
        }
        return sum/cnt;
    }
};
```

