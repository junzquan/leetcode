# [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if ((nums[mid] > nums[mid + 1]) || ((nums[mid] < nums[mid + 1]) && nums[right] < nums[mid]))
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
```

- 当`nums[mid] > nums[mid + 1]` 时，最小值在右半部分；
- 当`nums[mid] < nums[mid + 1]` 且 `nums[right] < nums[mid]` 时，最小值在右半部分；
- 其余情况最小值在左半部分。