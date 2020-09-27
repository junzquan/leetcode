# [11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)

## 双指针

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r)
        {
            int h = min(height[l], height[r]);
            res = max(res, h * (r - l));
            (height[l] < height[r]) ? ++l : --r;
        }
        return res;
    }
};
```

- 左指针从数组开头往右扫，右指针从数组结尾往前扫，对于某个左右指针 `l` 和 `r` ，能够容纳的水为 `h * (r - l)` ，其中 `h` 为左右指针所在高度的较小值；
- 然后更新高度较小的指针，重复过程知道左右指针相遇。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)

