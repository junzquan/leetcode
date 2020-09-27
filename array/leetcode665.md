# [665. 非递减数列](https://leetcode-cn.com/problems/non-decreasing-array/)

## 贪心

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt <= 1; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                cnt++;
                if (i - 2 < 0 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
            }
        }
        return cnt <= 1;
    }
};
```

**当 `nums[i-1] > nums[i]` 时 ，有两种情况**

- 当 `nums[i-2] <= nums[i]` 时，只需要将 `nums[i-1]` 的值改为 `nums[i]` 即可把数组变成非递减的；
- 当 `nums[i-2] > nums[i]` 时，更改 `nums[i]` 的值会是更好的选择，否则需要将 `nums[i-1]` 和 `nums[i-2]` 的值都改为 `nums[i]` 才能使数列变成非递减的。



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)