# [26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int slowPtr = 0;
        
        for (int fastPtr = 1; fastPtr < nums.size(); fastPtr++)
        {
            if (nums[slowPtr] != nums[fastPtr])
            {
                slowPtr++;
                nums[slowPtr] = nums[fastPtr];
            }
        }
        
        return slowPtr + 1;
    }
};
```

- 使用快慢指针，当 `nums[fastPtr] == nums[slowPtr]` 时，快指针移动，直到他们不相等；
- 然后更新慢指针，将快指针指向的值赋给慢指针；
- 最后返回 `slowPtr + 1` 。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)

