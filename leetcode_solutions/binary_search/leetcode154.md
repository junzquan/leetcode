# [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else
                right = right - 1;
        }
        return nums[left];
    }
};
```

- 当`nums[mid] > nums[right]`时，最小值存在于右半区间；

- 当`nums[mid] < nums[right]`时，最小值存在于左半区间；

- 【**难点** 】当`nums[mid] == nums[right]`时，最小值可能存在于左半区间或者右半区间，如[1,1,1,0,1] [1,0,1,1,1]，此时令`right = right - 1`。

  [参考](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/154-find-minimum-in-rotated-sorted-array-ii-by-jyd)