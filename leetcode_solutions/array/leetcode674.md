# [674. 最长连续递增序列](https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/)

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ret = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || nums[i - 1] < nums[i])
                ret = max(ret, ++cnt);
            else
                cnt = 1;
        }
        return ret;
    }
};

```

