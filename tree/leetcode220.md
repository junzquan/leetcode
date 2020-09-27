# [220. 存在重复元素 III](https://leetcode-cn.com/problems/contains-duplicate-iii/)

## 二叉搜索树

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<double> set_;
        for (int i = 0; i < nums.size(); i++)
        {
            auto s = set_.lower_bound((double)nums[i] - (double)t);
            if (s != set_.end() && *s <= (double)nums[i] + (double)t)
            {
                return true;
            }

            set_.insert(nums[i]);
            if (set_.size() > k)
            {
                set_.erase(nums[i - k]);
            }
        }
        return false;
    }
};
```

- 维护一棵节点数小于 `k` 的二叉搜索树；
- 用 `set::lower_bound` 寻找大于等于 `nums[i] - t` 的最小值；
- 

### 复杂度分析

- 时间复杂度：O(n log(min(n, k)))
- 空间复杂度：O(min(n, k))
