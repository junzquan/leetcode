# [697. 数组的度](https://leetcode-cn.com/problems/degree-of-an-array/)

```cpp
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int ans = nums.size();
        int degree = 0;
        unordered_map<int, pair<int, int>> pos;
        unordered_map<int, int> cnts;

        for (int i = 0; i < nums.size(); i++)
        {
            cnts[nums[i]]++;
            if (pos.find(nums[i]) == pos.end())
            {
                pos[nums[i]] = make_pair(i, i);
            }
            else
            {
                pos[nums[i]].second = i;
            }
            degree = max(degree, cnts[nums[i]]);
        }

        for (auto i : cnts)
        {
            if (degree == i.second)
            {
                ans = min(ans, pos[i.first].second - pos[i.first].first + 1);
            }
        }

        return ans;
    }
};
```

- 遍历数组，确定数字的左右位置，以及数组的度；
- 遍历计数`map`，计算最大的度的子数组长度。