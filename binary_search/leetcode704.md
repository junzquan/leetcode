# [704. 二分查找](https://leetcode-cn.com/problems/binary-search/)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = (unsigned)(left + right) >> 1;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return (nums[left] == target) ? left : -1;
    }
};
```

