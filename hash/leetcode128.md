# [128. 最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/)

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (long num : nums)
        {
            // 如果num-1不在set中，num是一个新序列的起点
            if (!s.count(num - 1))
            {
                int len = 0;
                // 计算以num为起点的序列长度
                while (s.count(num++)) len++;
                res = max(res, len);
            }
        }
        return res;
    }
};
```

- 将 `nums` 中的元素加入到 `set` 中；
- 遍历 `nums`，如果 `num - 1` 不在 `set` 中，则当前元素是一个序列的起点；
- 然后用 `while` 循环计算以 `num` 为起点的序列长度，并更新结果 `res` 。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)



