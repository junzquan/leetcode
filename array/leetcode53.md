# [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN;
        int sum = 0;
        for (auto i : nums)
        {
            sum = (sum <= 0) ? i : (sum + i);
            ret = max(ret, sum);
        }
        return ret;
    }
};
```

- 遍历 `nums`，当 `sum <= 0` 时，证明 `sum` 对结果没有增益，则令 `sum = i` ；
- 当 `sum > 0` 时，令 `sum = sum + i`，比较 `sum` 和 `ret`，取最大值。 

