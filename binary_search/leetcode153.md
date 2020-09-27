# [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (unsigned)(left + right) >> 1;
            if(nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};
```

- 当`nums[mid] > nums[right]` 时，`nums[mid]` 不可能是最小值，将其排除，并搜索右半部分；
- 否则 `nums[mid]` 有可能是最小值，保留 `nums[mid]`，搜索左半部分。