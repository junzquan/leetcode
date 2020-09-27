# [55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
```

- 用 `k` 表示能到达的最远距离，而 `i > k` 表示 `i` 之前的最远距离 `k` 无法到达 `i` ，此时应该返回 `false` 。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)

