# [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/)

## [牛顿迭代法]([https://zh.wikipedia.org/wiki/%E7%89%9B%E9%A1%BF%E6%B3%95](https://zh.wikipedia.org/wiki/牛顿法))

```cpp
class Solution {
public:
    int mySqrt(int x) {
        long s = x;        
        while (s * s > x)
            s = (s + x / s) / 2;
        return s;
    }
};
```

## 二分法

平方根的范围在[0, x]之间，使用二分法每次排除一半的数字。

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left < right)
        {
            int mid = (left + (long long)right + 1) >> 1;
            if (mid <= x / mid) left = mid;
            else right = mid - 1;
        }
        return right;
    }
};
```