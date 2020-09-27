# [442. 数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (auto i : nums)
        {
            int v = abs(i);
            if (nums[v - 1] < 0) 
                res.push_back(v);
            else
                nums[v - 1] *= -1;
        }
        return res;
    }
};
```

- 将出现过的数字作为数组的index（访问元素时需要减一）；
- 如果出现一次的，将该index下的数取相反数，记录此时的状态；
- 如果值为index的数字再出现一次（此时index索引的值为负数），那么这个数字就出现了两次。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)