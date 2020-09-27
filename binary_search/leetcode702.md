# [702. 搜索长度未知的有序数组](https://leetcode-cn.com/problems/search-in-a-sorted-array-of-unknown-size/)

```cpp
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // get size of array
        int left = 0, right = INT_MAX;
        int mid = 0;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (reader.get(mid) == INT_MAX)
                right = mid;
            else
                left = mid + 1;
        }
        
        // search target
        int lo = 0, hi = left;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (reader.get(mid) == target)
                return mid;
            else if (reader.get(mid) > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        return -1;
    }
};
```

- 首先搜索`array`右边界，确定`array`大小
- 然后普通二分搜素得到结果

