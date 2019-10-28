# [448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> cnts(nums.size() + 1, 0);
        vector<int> ans;
        for (auto i : nums)
        {
            cnts[i]++;
        }
        for (int i = 1; i < cnts.size(); i++)
        {
            if (cnts[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

- 创建`cnts`数组，统计`nums`中数字出现的次数；
- 遍历`cnts`，找出出现次数为0的数字。