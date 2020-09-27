# [81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

## 暴力法

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (auto i : nums)
            if (i == target)
                return true;
        return false;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)

## 二分法

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi)
        {
            // 去掉数组首尾的重复元素
            while (lo < hi && nums[lo] == nums[lo + 1]) ++lo;
            while (lo < hi && nums[hi] == nums[hi - 1]) --hi;
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return true;
            
            // 左半区间有序
            if (nums[lo] <= nums[mid])
            {
                // 目标在左半区间
                if (target < nums[mid] && target >= nums[lo]) hi = mid - 1;
                else lo = mid + 1;
            }
            // 右半区间有序
            else
            {
                // 目标在右半区间
                if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
    }
};
```

### 复杂度分析

- 时间复杂度：O(log N)
- 空间复杂度：O(1)