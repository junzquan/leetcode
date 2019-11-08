# [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                index.push_back(m.find(target - nums[i])->second);
                index.push_back(i);
                break;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return index;
    }
};
```

- 创建哈希表，`key` 是 `nums[i]` ，`value` 是索引 `i`；
- 当访问到 `nums[i]` 时，如果在哈希表中找到值 `target - nums[i]`，就把 `i` 和那个值的索引放入 `vector` 并退出循环；
- 否则将 `nums[i]` 和索引 `i` 加入哈希表中。

