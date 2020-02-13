# [566. 重塑矩阵](https://leetcode-cn.com/problems/reshape-the-matrix/)

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) return nums;

        vector<vector<int>> res;
        int index = 0;
        for (int i = 0; i < r; i++)
        {
            vector<int> curRow;
            for (int j = 0; j < c; j++)
            {
                curRow.push_back(nums[index / n][index % n]);
                index++;
            }
            res.push_back(curRow);
        }
        return res;
    }
};
```

### 复杂度分析

- 时间复杂度：O(m * n)
- 空间复杂度：O(1)