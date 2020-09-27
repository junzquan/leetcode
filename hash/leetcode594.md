# [594. 最长和谐子序列](https://leetcode-cn.com/problems/longest-harmonious-subsequence/)

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map_;
        for (auto i : nums)
            map_[i]++;
        
        int longest = 0;
        for (auto m : map_)
        {
            int val = m.first;
            if (map_.find(val - 1) != map_.end() && map_[val - 1] + m.second > longest)
                longest = map_[val - 1] + m.second;
            if (map_.find(val + 1) != map_.end() && map_[val + 1] + m.second > longest)
                longest = map_[val + 1] + m.second;
        }
        return longest;
    }
};
```

- 扫描数组 `nums` ，统计每个数字出现次数；
- 遍历哈希表，计算每个元素和它的加一元素或减一元素的和谐子序列长度，并更新结果 `longest` 。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)



