# [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int left = 0;
        int right = n;
        while (left < right)
        {
            int mid = (unsigned)(left + right) >> 1;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
```

