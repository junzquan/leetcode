# [278. 第一个错误的版本](https://leetcode-cn.com/problems/first-bad-version/)

## 二分查找法

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) { hi = mid; }
            else { lo = mid + 1; }
        }
        
        return lo;
    }
};
```

- 当mid是坏版本时，mid右侧不可能有第一个坏版本（不包括mid），所以搜索范围变为[lo, mid]；
- 当mid时好版本时，第一个坏版本肯定在右侧，所以搜索范围变为[mid + 1, hi]；
- lo == hi时，有第一个错误版本的位置。