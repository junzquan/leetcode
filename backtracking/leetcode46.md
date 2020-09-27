# [46. 全排列](https://leetcode-cn.com/problems/permutations/)

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(nums, track, res);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track, vector<vector<int>>& res)
    {
        if (nums.size() == track.size())
        {
            res.push_back(vector<int>(track));
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (find(track.begin(), track.end(), nums[i]) != track.end())
            {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, track, res);
            track.pop_back();
        }
    }
};
```

### 复杂度分析

- 时间复杂度：O(N!)
- 空间复杂度：O(N)

