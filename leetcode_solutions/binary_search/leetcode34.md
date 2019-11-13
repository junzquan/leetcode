# [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        vector<int> ret;
        
        // find left boundary
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (unsigned)(left + right) >> 1;	// get left median
            cout << mid << endl;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        (nums[left] == target) ? ret.push_back(left) : ret.push_back(-1);
        
        // find right boundary
        left = 0;
        right = nums.size() - 1;
        while (left < right)
        {
            int mid = (unsigned)(left + right + 1) >> 1;	// get right median
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        (nums[left] == target) ? ret.push_back(left) : ret.push_back(-1);
        return ret;
    }
};
```

- 使用二分查找分别找出左右边界

参考[十分好用的二分查找模板]( https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/ )

