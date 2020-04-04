# [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)

## 暴力法

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int res = 0;
        auto begin_iter = height.cbegin();
        auto end_iter   = height.cend();
        for (int i = 0; i < n; i++)
        {
            int max_l = *max_element(begin_iter, begin_iter + i + 1);
            int max_r = *max_element(begin_iter + i, end_iter);
            res += min(max_l, max_r) - height[i];
        }
        return res;
    }
};
```

- 对每一个位置 `height[i]` ，求出其左边最大值和右边最大值，然后取它们的较小值减去当前位置的高度，并加入答案。

### 复杂度分析

- 时间复杂度：O(N<sup>2</sup>)
- 空间复杂度：O(1)



## 动态规划

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        vector<int> l_height(n, 0);
        vector<int> r_height(n, 0);
        for (int i = 0; i < n; i++)
        {
            l_height[i] = (i == 0) ? height[i] : max(l_height[i - 1], height[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            r_height[i] = (i == n - 1) ? height[i] : max(r_height[i + 1], height[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += min(l_height[i], r_height[i]) - height[i];
        }
        return res;
    }
};
```

- `l_height[i]` 表示数组 `0 ~ i` 范围内的最大值；
- `r_height[i]` 表示数组 `(n - 1) ~ i` 范围内的最大值；
- 当遍历原数组 `height` 时，可以知道 `height[i]` 左边的最大值 `l_height[i]` 和右边的最大值 `r_height[i]` ，用它们的较小值减去 `height[i]` ，便是位置 `i` 的接雨水量。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)



## 双指针

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n == 0)
        {
            return 0;
        }
        int l = 0;
        int r = n - 1;
        int max_l = height[0];
        int max_r = height[n - 1];
        int res = 0;
        while (l < r)
        {
            if (max_l < max_r)
            {
                res += max_l - height[l];
                max_l = max(max_l, height[++l]);
            }
            else
            {
                res += max_r - height[r];
                max_r = max(max_r, height[--r]);
            }
        }
        return res;
    }
};
```

- 维护两个变量 `max_l` 和 `max_r` ，`max_l` 表示数组 `0 ~ l` 的最大值，`max_r` 表示数组 `r ~ n-1` 的最大值；
- 当 `max_l < max_r` 时，我们可以知道位置 `l` 的雨水量为 `max_l - height[l]` ，因为决定该位置雨水量的是 `max_l` 和 `max_r` 的较小值；反之亦然。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)

